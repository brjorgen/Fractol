/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:24:58 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mem/mem.h"
#include "../strings/strings.h"
#include "./buffers.h"
#include <unistd.h>
#include <stdio.h>

void	buff_get_input(char *buff)
{
	char *pos;

	ft_bzero(buff, BUFFSIZE);
	read(0, buff, BUFFSIZE);
	if ((pos = ft_strchr(buff, '\n')) != NULL)
	{
		*pos = '\0';
	}
}
