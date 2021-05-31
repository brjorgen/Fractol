/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/24 17:51:54 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./strings.h"

void	ft_strncpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (src[i] && i <= size)
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= size)
	{
		dest[i] = 0;
		i++;
	}
}
