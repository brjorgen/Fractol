/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 13:45:14 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./strings.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const uint8_t	*ca;
	const uint8_t	*cb;

	if (!s1 || !s2)
		return (0);
	ca = (const uint8_t *)s1;
	cb = (const uint8_t *)s2;
	while ((*ca && *cb) && (*ca == *cb))
	{
		ca++;
		cb++;
	}
	return ((int)*ca - *cb);
}
