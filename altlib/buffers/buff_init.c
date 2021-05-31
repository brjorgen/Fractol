/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:27:35 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../altlib.h"

char	*buff_init(void)
{
	static char	buff[BUFFSIZE];
	char		*buff_ptr;

	buff_ptr = &buff[0];
	return (buff_ptr);
}
