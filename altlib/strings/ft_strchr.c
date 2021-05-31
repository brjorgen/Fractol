/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 13:46:05 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./strings.h"

char	*ft_strchr(const char *s, int c)
{
	const uint8_t *ret_ptr;

	ret_ptr = (const uint8_t *)s;
	while (*ret_ptr)
	{
		if (*ret_ptr == (uint8_t)c)
			return ((char *)ret_ptr);
		ret_ptr++;
	}
	return (NULL);
}
