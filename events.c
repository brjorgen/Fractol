/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:28:44 by brjorgen          #+#    #+#             */
/*   Updated: 2020/08/31 17:47:31 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int			close_win(void *param)
{
	mlxdel(param);
	exit(EXIT_SUCCESS);
	return (0);
}

int			red_cross(void *param)
{
	close_win(param);
	return (0);
}

double		interpolate(double start, double end, double interpolation)
{
	return ((1.0 - interpolation) * start) + (interpolation * end);
}

void		zoom(int x, int y, t_viewport *viewport, double z)
{
	double	w;
	double	h;
	double	nw;
	double	nh;

	w = (viewport->xmax - viewport->xmin) * (viewport->zoom);
	h = (viewport->ymax - viewport->ymin) * (viewport->zoom);
	nw = (viewport->xmax - viewport->xmin) * (viewport->zoom * z);
	nh = (viewport->ymax - viewport->ymin) * (viewport->zoom * z);
	viewport->zoom *= z;
	viewport->offx -= ((double)x / WTH) * (nw - w);
	viewport->offy -= ((double)y / HGT) * (nh - h);
	viewport->max += 10;
}

int			key_hook(int keycode, t_env *env)
{
	double	w;
	double	h;

	w = (env->viewport.xmax - env->viewport.xmin) * env->viewport.zoom;
	h = (env->viewport.ymax - env->viewport.ymin) * env->viewport.zoom;
	if (keycode == KEY_P)
		env->palette->cycle += 1;
	if (keycode == KEY_O && env->palette->cycle > 2)
		env->palette->cycle -= 1;
	if (keycode == KEY_UP)
		env->viewport.offy -= h * 0.05f;
	if (keycode == KEY_DOWN)
		env->viewport.offy += h * 0.05f;
	if (keycode == KEY_LEFT)
		env->viewport.offx -= w * 0.05f;
	if (keycode == KEY_RIGHT)
		env->viewport.offx += w * 0.05f;
	if (keycode == KEY_ESC)
		close_win(env);
	if (keycode == KEY_L)
		env->mouselock = 1 - env->mouselock;
	draw_hooks(keycode, env);
	render(env);
	return (0);
}
