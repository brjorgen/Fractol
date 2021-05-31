/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/24 17:51:54 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./binary_trees.h"

t_tree	*btree_search(t_tree **tree_root, void *data,
	int (*cmp_fn)(void *, void *))
{
	int cmp_val;

	if (!tree_root)
	{
		return (NULL);
	}
	cmp_val = cmp_fn((*tree_root)->data, data);
	if (cmp_val == 0)
	{
		return (*tree_root);
	}
	else if (cmp_val == 1)
	{
		return (btree_search(&(*tree_root)->l_node, data, cmp_fn));
	}
	else
	{
		return (btree_search(&(*tree_root)->r_node, data, cmp_fn));
	}
}
