/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 13:45:45 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./strings.h"

char	*ft_strclean(char *str)
{
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (*str == ' ')
	{
		str++;
	}
	while (*(str + len) == ' ')
	{
		str--;
		len--;
	}
	return (str);
}
