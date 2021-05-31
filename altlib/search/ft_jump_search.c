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

#include "../altlib.h"
#include <math.h>

int	ft_jump_search(const int to_search[], const int to_find,
	const size_t array_size)
{
	size_t index;
	size_t jump_size;

	index = 0;
	jump_size = sqrt(array_size);
	while (to_search[index] < to_find && index <= array_size)
	{
		index += jump_size;
	}
	while (to_search[index] >= to_find)
	{
		index--;
	}
	return (to_search[index]);
}
