/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:41:56 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_maps.h"

void	hashmap_insert_elem(t_mapelem *to_insert, t_mapelem *map,
	size_t array_size)
{
	size_t		index;
	t_mapelem	*last_item;

	index = hash_data(to_insert->key, array_size);
	if (!map[index].key)
	{
		map[index] = *to_insert;
	}
	else if (map[index].key)
	{
		last_item = hashmap_get_last_list_elem(&map[index]);
		last_item->next = to_insert;
	}
}
