/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:41:24 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hash_maps/hash_maps.h"
#include "../strings/strings.h"

t_mapelem	hashmap_get_elem(const char *key, const t_mapelem *map,
	size_t mapsize)
{
	size_t		index;
	t_mapelem	*traveller;

	index = hash_data(key, mapsize);
	traveller = (t_mapelem *)map;
	while (ft_strcmp(key, traveller[index].key))
	{
		traveller[index] = *traveller[index].next;
	}
	return (traveller[index]);
}
