/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:46:21 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

t_list	*list_find(t_list *list_head,
	bool (*predicate_match_function)(t_list *))
{
	t_list *list_traveller;

	if (!list_head)
		return (NULL);
	list_traveller = list_head;
	while (!predicate_match_function(list_traveller))
	{
		list_traveller = list_traveller->next;
	}
	return (list_traveller);
}
