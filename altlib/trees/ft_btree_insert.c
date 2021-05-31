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

#include "./binary_trees.h"

void	btree_insert(t_tree **tree_root, void *data, size_t size,
	int (*cmp_fn)(void *, void *))
{
	if (!*tree_root)
	{
		(*tree_root)->data = malloc(size);
		(*tree_root)->data = data;
		(*tree_root)->l_node = NULL;
		(*tree_root)->r_node = NULL;
	}
	else if (cmp_fn((*tree_root)->data, data) == -1)
	{
		btree_insert(&(*tree_root)->l_node, data, size, cmp_fn);
	}
	else
	{
		btree_insert(&(*tree_root)->r_node, data, size, cmp_fn);
	}
}
