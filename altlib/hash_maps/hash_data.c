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

size_t	hash_data(const char *key, const size_t array_size)
{
	unsigned int	val;
	char			*keyptr;

	keyptr = (char *)key;
	val = 0;
	while (*keyptr)
	{
		val += *keyptr;
		keyptr++;
	}
	return (val % array_size);
}
