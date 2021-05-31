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

#ifndef DYN_ARRAYS_H
# define DYN_ARRAYS_H

# include <stdlib.h>

/*
**	Dynamic Arrays
*/
enum				e_dynarray_stats
{
	DYNARRAY_DEFAULT_INIT_SIZE = 500,
};

typedef struct		s_dynarray
{
	void			**data;
	size_t			used;
	size_t			capacity;
}					t_dynarray;

#endif
