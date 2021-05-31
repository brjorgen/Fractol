/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:40:07 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_MAPS_H
# define HASH_MAPS_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct			s_mapelem
{
	char				*key;
	void				*value;
	struct s_mapelem	*next;
}						t_mapelem;

t_mapelem				*hashmap_init(size_t size);
t_mapelem				*hashmap_init_elem(char *key, void *value,
	size_t size);
t_mapelem				*hashmap_get_last_list_elem(t_mapelem *map);
t_mapelem				hashmap_get_elem(const char *key,
	const t_mapelem *map, size_t mapsize);
size_t					hash_data(const char *key, const size_t array_size);
void					hashmap_insert_elem(t_mapelem *to_insert,
	t_mapelem *map, size_t array_size);

#endif
