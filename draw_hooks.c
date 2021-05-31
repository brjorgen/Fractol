/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 23:23:57 by brjorgen          #+#    #+#             */
/*   Updated: 2020/08/31 17:46:57 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_hooks(int key, t_env *env)
{
	if (key >= KEY_1 && key <= KEY_1 + 3)
		env->palette = &get_palettes()[key - KEY_1];
	else if (key == KEY_ENTER)
		env->smooth = 1 - env->smooth;
}
