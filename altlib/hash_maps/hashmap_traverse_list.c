/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/11/24 17:51:54 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_maps.h"

t_mapelem	*hashmap_get_last_list_elem(t_mapelem *map)
{
	t_mapelem *traveller;

	traveller = map;
	while (traveller->next != NULL)
	{
		traveller = traveller->next;
	}
	return (traveller);
}
