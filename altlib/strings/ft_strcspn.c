/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 13:50:40 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./strings.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	const uint8_t	*s_ptr;
	const uint8_t	*reject_ptr;
	size_t			seg_size;

	s_ptr = (const uint8_t *)s;
	reject_ptr = (const uint8_t *)reject;
	seg_size = 0;
	while (!ft_strchr(s, *reject))
	{
		s_ptr++;
		reject_ptr++;
		seg_size++;
	}
	return (seg_size);
}
