/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:46:05 by brjorgen          #+#    #+#             */
/*   Updated: 2020/08/31 17:48:49 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	screen_to_complex(int x, int y, t_viewport *v)
{
	t_complex	p;

	p.re = (((double)x / WTH) * (v->xmax - v->xmin)) * v->zoom
		+ v->xmin + v->offx;
	p.im = (((double)y / HGT) * (v->ymax - v->ymin)) * v->zoom
		+ v->ymin + v->offy;
	return (p);
}

void		mandelbrot_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.0f;
	v->ymax = 1.0f;
	v->offx = -0.5f;
}

void		julia_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
}

void		burningship_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -2.0f;
	v->ymax = 1.0f;
	v->offx = -0.25f;
}

void		viewport_fit(t_viewport *v)
{
	double w;
	double h;

	w = v->xmax - v->xmin;
	h = v->ymax - v->ymin;
	if (w / h >= (float)WTH / HGT)
	{
		v->ymin = -(w * HGT / WTH / 2);
		v->ymax = w * HGT / WTH / 2;
	}
	else
	{
		v->xmin = -(h * WTH / HGT / 2);
		v->xmax = (h * WTH / HGT / 2);
	}
}
