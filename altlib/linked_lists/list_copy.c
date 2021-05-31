/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:47:09 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linked_lists.h"

t_list	*list_copy(t_list *list_head, bool (*check_stop_fn)(t_list *))
{
	t_list *traveller;
	t_list *new_list;

	traveller = list_head;
	new_list = list_init_list(traveller->data, sizeof(traveller->data));
	while (!check_stop_fn(traveller))
	{
		list_add_end(new_list, traveller);
		traveller = traveller->next;
	}
	return (new_list);
}
