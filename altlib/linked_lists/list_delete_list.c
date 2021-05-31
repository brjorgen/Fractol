/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/24 17:51:54 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linked_lists.h"

bool	list_delete_list(t_list *head)
{
	t_list *traveller;
	t_list *prev_traveller;

	if (!head)
		return (false);
	traveller = head;
	prev_traveller = head;
	while (traveller != NULL)
	{
		prev_traveller = traveller;
		traveller = traveller->next;
		list_delete_link(prev_traveller);
	}
	return (true);
}
