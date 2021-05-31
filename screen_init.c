/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:23:40 by brjorgen          #+#    #+#             */
/*   Updated: 2020/08/31 18:40:11 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <assert.h>

t_env		*mlxdel(t_env *env)
{
	if (env->image->img_ptr != NULL)
		mlx_destroy_image(env->scr.server, env->image->img_ptr);
	if (env->scr.window != NULL)
		mlx_destroy_window(env->scr.server, env->scr.window);
	if (env->data != NULL)
		free(env->data);
	error_handler("mlx killed.\n", 1);
	return (NULL);
}

void		screen_init(t_env *env)
{
	char	*title;

	title = "Fract'ol";
	if (
	(env->scr.server = mlx_init()) == NULL ||
	(env->scr.window = mlx_new_window(env->scr.server, WTH, HGT, title)) == NULL
	|| (env->image = new_image(env)) == NULL ||
	(env->data = malloc(sizeof(t_pixel) * WTH * HGT)) == NULL)
		mlxdel(env);
	env->image->img_str = mlx_get_data_addr(env->image->img_ptr
	, &env->image->bpp
	, &env->image->stride
	, &env->image->endian);
	env->mouse.isdown = 0;
	env->mouse.x = 0;
	env->mouse.y = 0;
	env->mouselock = 1 - env->fractal->mouse;
	env->palette = get_palettes();
	env->smooth = 1;
}

t_fractal	*get_fractals(void)
{
	static t_fractal array[__FRACTAL_TOTAL] = {
		{"mandelbrot", mandelbrot_viewport, 0},
		{"julia", julia_viewport, 1},
		{"burning_ship", burningship_viewport, 0},
		{"brain", julia_viewport, 1},
		{NULL, NULL, 0}
	};

	return (array);
}

t_fractal	*fractal_match(char *str)
{
	t_fractal	*f;
	int			i;

	f = get_fractals();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
		i++;
	}
	return (&f[i]);
}

void		reset_viewport(t_env *env)
{
	env->viewport.offx = 0;
	env->viewport.offy = 0;
	if (!env->fractal->name)
		error_handler("No such fractal.\nUsage: ./fractol\
	mandelbrot/julia/burning_ship/brain\n", 1);
	if (strcmp(env->fractal->name, "mandelbrot") == 0)
		mandelbrot_viewport(&env->viewport);
	else if (strcmp(env->fractal->name, "julia") == 0)
		julia_viewport(&env->viewport);
	else if (strcmp(env->fractal->name, "burning_ship") == 0)
		burningship_viewport(&env->viewport);
	else if (strcmp(env->fractal->name, "brain") == 0)
		julia_viewport(&env->viewport);
	viewport_fit(&env->viewport);
	env->viewport.max = 32;
	env->viewport.zoom = 1.0f;
}
