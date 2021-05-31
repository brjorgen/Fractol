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

#include "./mem.h"

void	*ft_memdup(const void *data, const size_t size)
{
	void *dup_data;

	dup_data = (void *)malloc(sizeof(void) * size);
	if (!dup_data)
	{
		return (NULL);
	}
	ft_memcpy(dup_data, data, size);
	return (dup_data);
}
