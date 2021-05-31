/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 13:58:47 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./strings.h"
#include "../mem/mem.h"
#include <stdio.h>

char	*ft_strnext(char *str, bool resetp)
{
	static size_t	front;
	static size_t	back;
	static char		buff[500];
	size_t			pos;

	if (!str)
		return (NULL);
	if (resetp)
		front = 0;
	pos = 0;
	ft_bzero(buff, sizeof(buff));
	back = front;
	while (str[front] && str[front] != ' ')
		front++;
	while (str[back] && back != front)
	{
		buff[pos] = str[back];
		back++;
		pos++;
	}
	front++;
	return (buff);
}
