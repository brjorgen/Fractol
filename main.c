/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:44:16 by brjorgen          #+#    #+#             */
/*   Updated: 2020/08/31 18:37:28 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				main(int argc, char **argv)
{
	t_env env;

	if (argc < 2 || !argv[1])
	{
		error_handler("No args passed.\nUsage: \
	./fractol mandelbrot/julia/burning_ship/brain\n", 1);
		return (0);
	}
	env.fractal = fractal_match(argv[1]);
	reset_viewport(&env);
	screen_init(&env);
	env.x = 0;
	env.y = 0;
	render(&env);
	mlx_key_hook(env.scr.window, key_hook, &env);
	mlx_expose_hook(env.scr.window, hook_expose, &env);
	mlx_hook(env.scr.window, 4, 1L << 2, hook_mousedown, &env);
	mlx_hook(env.scr.window, 5, 1L << 3, hook_mouseup, &env);
	mlx_hook(env.scr.window, 6, 1L << 6, hook_mousemove, &env);
	mlx_loop(env.scr.server);
	return (0);
}
