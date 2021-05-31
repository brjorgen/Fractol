/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:35:06 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALTLIB_H
# define ALTLIB_H

# include <stdint.h>
# include <stdlib.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "./hash_maps/hash_maps.h"
# include "./linked_lists/linked_lists.h"
# include "./dyn_arrays/dyn_arrays.h"
# include "./stacks/stacks.h"
# include "./search/search.h"
# include "./sorting/sorting.h"
# include "./strings/strings.h"
# include "./buffers/buffers.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *mem, size_t size);

#endif
