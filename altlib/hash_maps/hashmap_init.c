/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:40:41 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hash_maps.h"
#include "../mem/mem.h"

t_mapelem	*hashmap_init(size_t size)
{
	t_mapelem *hashmap;

	hashmap = (t_mapelem *)malloc(sizeof(t_mapelem) * size);
	if (!hashmap)
		return (NULL);
	ft_bzero(hashmap, sizeof(hashmap));
	return (hashmap);
}
