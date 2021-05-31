/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:34:55 by brjorgen          #+#    #+#             */
/*   Updated: 2020/08/31 17:51:32 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel		draw_mandelbrot(int col, int row, t_viewport *viewport)
{
	t_complex	c;
	t_complex	z;
	t_complex	temp;
	int			iter;

	c = screen_to_complex(col, row, viewport);
	z = screen_to_complex(col, row, viewport);
	iter = 0;
	while ((z.re * z.re + z.im * z.im) < (1 << 8) && iter < viewport->max)
	{
		temp.re = z.re * z.re - z.im * z.im + c.re;
		temp.im = z.re * z.im * 2 + c.im;
		if (z.re == temp.re && z.im == temp.im)
		{
			iter = viewport->max;
			break ;
		}
		z.re = temp.re;
		z.im = temp.im;
		iter++;
	}
	return ((t_pixel){.c = z, .i = iter});
}

t_pixel		draw_julia(int col, int row, t_viewport *viewport, t_mouse mouse)
{
	t_complex	c;
	t_complex	z;
	t_complex	temp;
	int			iter;

	c.im = mouse.x / 1000;
	c.re = mouse.y / 1000;
	z = screen_to_complex(col, row, viewport);
	iter = 0;
	while (((z.re * z.re) + (z.im * z.im)) < (1 << 8) && iter < viewport->max)
	{
		temp.re = z.re * z.re - z.im * z.im + c.re;
		temp.im = z.re * z.im * 2 + c.im;
		if (z.re == temp.re && z.im == temp.im)
		{
			iter = viewport->max;
			break ;
		}
		z.re = temp.re;
		z.im = temp.im;
		iter++;
	}
	return ((t_pixel){.c = z, .i = iter});
}

t_pixel		draw_burning_ship(int col, int row, t_viewport *viewport)
{
	t_complex	c;
	t_complex	z;
	t_complex	temp;
	int			iter;

	c = screen_to_complex(col, row, viewport);
	z = screen_to_complex(col, row, viewport);
	iter = 0;
	while ((z.re * z.re + z.im * z.im) < (1 << 8) && iter < viewport->max)
	{
		temp.re = z.re * z.re - z.im * z.im + c.re;
		temp.im = fabsl(z.re * z.re * z.im * z.im * 2) + c.im;
		if (z.re == temp.re && z.im == temp.im)
		{
			iter = viewport->max;
			break ;
		}
		z.re = temp.re;
		z.im = temp.im;
		iter++;
	}
	return ((t_pixel){.c = z, .i = iter});
}

t_pixel		draw_brain(int col, int row, t_viewport *viewport, t_mouse mouse)
{
	t_complex	c;
	t_complex	z;
	t_complex	temp;
	int			iter;

	c.im = mouse.x / 1000;
	c.re = mouse.y / 1000;
	z = screen_to_complex(col, row, viewport);
	iter = 0;
	while (((z.re * z.re) + (z.im * z.im)) < (1 << 8) && iter < viewport->max)
	{
		temp.re = fabs(z.re * z.re - z.im * z.im) + c.re;
		temp.im = (-2 * z.re * z.im) + c.im;
		if (z.re == temp.re && z.im == temp.im)
		{
			iter = viewport->max;
			break ;
		}
		z.re = temp.re;
		z.im = temp.im;
		iter++;
	}
	return ((t_pixel){.c = z, .i = iter});
}
