/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:23:08 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structures.h"

t_dynarray	*dynarray_init(size_t capacity)
{
	t_dynarray	*dyn_a;

	dyn_a = (t_dynarray *){0};
	if (capacity)
	{
		dyn_a->data = malloc(capacity);
		dyn_a->capacity = capacity;
	}
	else
	{
		dyn_a->data = malloc(DYNARRAY_DEFAULT_INIT_SIZE);
		dyn_a->capacity = DYNARRAY_DEFAULT_INIT_SIZE;
	}
	dyn_a->used = 0;
	return (dyn_a);
}

bool		dynarray_resize(t_dynarray *dynarray, size_t size)
{
	t_dynarray	*new_dynarray;
	size_t		newsize;

	newsize = size ? (dynarray->capacity + size) : (dynarray->capacity * 2);
	new_dynarray = (t_dynarray *){0};
	if (!(new_dynarray->data = malloc(newsize)))
		return (false);
	ft_memcpy(new_dynarray->data, dynarray->data, dynarray->capacity);
	new_dynarray->capacity = newsize;
	new_dynarray->used = dynarray->capacity;
	free(dynarray->data);
	dynarray = new_dynarray;
	return (true);
}

void		dynarray_add(t_dynarray *dynarray, const void *data,
	const size_t size)
{
	if (dynarray->used + size >= dynarray->capacity)
		dynarray_resize(dynarray, size);
	ft_memcpy(dynarray->data + dynarray->used, data, size);
}
