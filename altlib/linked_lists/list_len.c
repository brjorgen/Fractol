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

size_t	list_len(t_list *head)
{
	t_list *traveller;
	size_t len;

	if (!head)
		return (-1);
	traveller = head;
	len = 0;
	while (traveller != NULL)
	{
		len++;
		traveller = traveller->next;
	}
	return (len);
}
