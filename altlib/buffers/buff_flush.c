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

#include "./buffers.h"
#include "../strings/strings.h"
#include "../mem/mem.h"

bool	buff_flush(char *buff_ptr)
{
	if (!buff_ptr)
		return (false);
	ft_putstr(buff_ptr);
	ft_bzero(buff_ptr, BUFFSIZE);
	return (true);
}
