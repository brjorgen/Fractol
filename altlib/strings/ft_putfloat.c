/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 13:50:14 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../altlib.h"

void	ft_putfloat(float n)
{
	int	round;
	int	count;

	round = (int)n;
	ft_putnbr(round);
	ft_putchar('.');
	n -= (float)round;
	count = 3;
	while (n)
	{
		if (!count)
			break ;
		n *= 10;
		round = (int)n;
		ft_putnbr(n);
		n -= (float)round;
		count--;
	}
}
