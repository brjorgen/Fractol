/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:42:36 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_maps.h"
#include "../mem/mem.h"

t_mapelem	*hashmap_init_elem(char *key, void *value, size_t size)
{
	t_mapelem	*entry;

	entry = (t_mapelem *)malloc(sizeof(t_mapelem));
	entry->key = key;
	entry->value = malloc(size);
	ft_memcpy(entry->value, value, size);
	entry->next = NULL;
	return (entry);
}
