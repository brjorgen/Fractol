/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:17:19 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREES_H
# define BINARY_TREES_H
# include <stdlib.h>
# include <stdbool.h>

typedef struct		s_tree
{
	void			*data;
	size_t			size;
	struct s_tree	*l_node;
	struct s_tree	*r_node;
}					t_tree;

void				btree_insert(t_tree **tree_root, void *data, size_t size,
	int (*cmp_fn)(void *, void *));
t_tree				*btree_search(t_tree **tree_root, void *data,
	int (*cmp_fn)(void *, void *));
void				btree_delete(t_tree *tree_root, void *data);
void				btree_map(t_tree *tree_root, void (*f)(t_tree *, void *));

#endif
