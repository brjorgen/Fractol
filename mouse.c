/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 22:13:54 by brjorgen          #+#    #+#             */
/*   Updated: 2020/08/31 17:34:23 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_expose(t_env *env)
{
	render(env);
	return (0);
}

int		hook_mousedown(int button, int x, int y, t_env *env)
{
	if (button == 4)
	{
		zoom(x, y, &env->viewport, 1 / ZOOM);
		render(env);
	}
	else if (button == 5)
	{
		zoom(x, y, &env->viewport, ZOOM);
		render(env);
	}
	if (y < 0)
		return (0);
	env->mouse.isdown |= 1 << button;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	env->mouse.isdown &= ~(1 << button);
	return (0);
}

int		hook_mousemove(int x, int y, t_env *env)
{
	double w;
	double h;

	env->mouse.lastx = env->mouse.x;
	env->mouse.lasty = env->mouse.y;
	env->mouse.x = x;
	env->mouse.y = y;
	if (!env->mouselock)
		env->viewport.mouse = screen_to_complex(x, y, &env->viewport);
	if (env->mouse.isdown & (1 << 1))
	{
		w = (env->viewport.xmax - env->viewport.xmin) * env->viewport.zoom;
		h = (env->viewport.ymax - env->viewport.ymin) * env->viewport.zoom;
		env->viewport.offx += (double)(env->mouse.lastx - x)
			/ WTH * w;
		env->viewport.offy += (double)(env->mouse.lasty - y)
			/ HGT * h;
	}
	if (env->mouse.isdown || (env->fractal->mouse && !env->mouselock))
		render(env);
	return (0);
}
