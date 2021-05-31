/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:38:50 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:39:20 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

static char	*my_strchr(const char *s, char c)
{
	char *ret_ptr;

	ret_ptr = (char *)s;
	while (*ret_ptr)
	{
		if (*ret_ptr == c)
			return ((char *)ret_ptr);
		ret_ptr++;
	}
	return (NULL);
}

static int	ft_index_nb(long nb)
{
	int		i;

	i = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		i = i * 10;
	}
	return (i);
}

float		ft_atof(const char *str)
{
	int		decimal;
	char	*ptr;
	float	ret;

	ret = (float)ft_atoi(str);
	if (!(ptr = my_strchr(str, '.')))
		ptr = my_strchr(str, ',');
	if (ptr == NULL)
		return (ret);
	decimal = ft_atoi(++ptr);
	ret += (float)(decimal) / (float)ft_index_nb(decimal);
	return (ret);
}
