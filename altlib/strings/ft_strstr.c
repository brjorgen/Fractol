/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:49:40 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/21 19:49:40 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./strings.h"
#include "../mem/mem.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *haystackptr;
	const char *needleptr;

	if (*needle == '\0')
	{
		return (NULL);
	}
	while (*haystack)
	{
		haystackptr = haystack;
		needleptr = needle;
		while (*haystack && *needleptr && *haystack == *needleptr)
		{
			haystack++;
			needleptr++;
		}
		if (!*needleptr)
			return (char *)haystackptr;
		haystack = haystackptr + 1;
	}
	return (NULL);
}
