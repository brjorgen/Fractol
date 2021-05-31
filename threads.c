/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:41:50 by brjorgen          #+#    #+#             */
/*   Updated: 2020/08/31 17:52:30 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel		fractal_caller(t_thread *t, int row, int col)
{
	t_pixel	pixel;

	if (ft_strcmp(t->env->fractal->name, "mandelbrot") == 0)
		pixel = draw_mandelbrot(col, row, &t->env->viewport);
	else if (ft_strcmp(t->env->fractal->name, "burning_ship") == 0)
		pixel = draw_burning_ship(col, row, &t->env->viewport);
	else if (ft_strcmp(t->env->fractal->name, "julia") == 0)
		pixel = draw_julia(col, row, &t->env->viewport, t->env->mouse);
	else if (ft_strcmp(t->env->fractal->name, "brain") == 0)
		pixel = draw_brain(col, row, &t->env->viewport, t->env->mouse);
	else
	{
		pixel = (t_pixel){{0, 0}, 0};
		error_handler("Unexpected error. aborting.", 1);
	}
	return (pixel);
}

void		*render_thread(void *m)
{
	t_thread		*t;
	t_pixel			pixel;
	int				col;
	int				row;

	t = (t_thread *)m;
	row = HGT / THREADS * t->id;
	while (row < HGT / THREADS * (t->id + 1))
	{
		col = 0;
		while (col < WTH)
		{
			pixel = fractal_caller(t, row, col);
			pixel_to_image(t->env->image->img_str,\
			col, row, get_color(pixel, t->env));
			col++;
		}
		row++;
	}
	return (NULL);
}

void		render(t_env *env)
{
	t_render		*r;
	int				i;

	mlx_clear_window(env->scr.server, env->scr.window);
	i = 0;
	r = &env->render;
	while (i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].env = env;
		pthread_create(r->threads + i
		, NULL, render_thread
		, &(r->args[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(r->threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->scr.server
	, env->scr.window
	, env->image->img_ptr, 0, 0);
}
