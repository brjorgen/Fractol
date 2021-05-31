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
#include "../strings/strings.h"

void	list_print(t_list *head)
{
	t_list *traveller;

	traveller = head;
	while (traveller)
	{
		ft_putstr(traveller->data);
		ft_putstr("->");
		traveller = traveller->next;
	}
}
