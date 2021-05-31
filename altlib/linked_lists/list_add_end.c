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

bool	list_add_end(t_list *head, t_list *tail)
{
	t_list *traveller;

	if (!head || !tail)
		return (false);
	traveller = head;
	while (traveller->next != NULL)
		traveller = traveller->next;
	traveller->next = tail;
	return (true);
}
