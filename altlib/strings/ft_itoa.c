/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:42:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:48:21 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include <stdlib.h>

static int	ft_nblen(long nb)
{
	int		i;

	i = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		i = i * 10;
	}
	return (i);
}

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	while (n-- > 0)
		*s2++ = (unsigned char)c;
	return (s);
}

static void	*ft_memalloc(size_t size)
{
	char	*pointeur;

	if (!(pointeur = (char *)malloc(sizeof(char) * (size))))
		return (NULL);
	ft_memset(pointeur, '\0', size);
	return (pointeur);
}

static char	*ft_strnew(size_t size)
{
	char	*n;

	n = (char *)ft_memalloc(size + 1);
	return (n);
}

char		*ft_itoa(int n)
{
	long	nb;
	char	*ret;
	int		size;
	int		i;
	int		modulo;

	nb = (long)n;
	size = ft_nblen(nb);
	if (!(ret = ft_strnew(size)))
		return (0);
	size = 0;
	if (n < 0)
	{
		ret[size++] = '-';
		nb = nb * -1;
	}
	i = ft_nblen(nb);
	while (i > 0)
	{
		modulo = nb % i;
		ret[size++] = (nb / i) + 48;
		i = i / 10;
		nb = modulo;
	}
	return (ret);
}
