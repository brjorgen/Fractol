/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:33:23 by brjorgen          #+#    #+#             */
/*   Updated: 2020/08/31 18:04:05 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_to_image(char *img_str, int x, int y, uint32_t col)
{
	uint32_t *ptr;

	ptr = (uint32_t *)(void *)img_str;
	if (x >= 0 && y >= 0 && x < WTH && y < HGT)
		ptr[x + y * WTH] = col;
}

void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WTH || y < 0 || y >= HGT)
		return ;
	*(int *)(image->img_str + ((x + y * WTH) * image->bpp)) = color;
}

void	clear_image(t_image *image)
{
	ft_bzero(image->img_str, WTH * HGT * (image->bpp - 3));
}

t_image	*del_image(t_env *env, t_image *image)
{
	if (image != NULL)
	{
		if (image->img_ptr != NULL)
			mlx_destroy_image(env->scr.server, image->img_ptr);
		free(image);
	}
	return (NULL);
}

t_image	*new_image(t_env *env)
{
	t_image		*img;

	if ((img = malloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->img_ptr = mlx_new_image(env->scr.server, WTH, HGT)) == NULL)
		return (del_image(env, img));
	img->img_str = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->stride,
			&img->endian);
	img->bpp /= 8;
	return (img);
}
