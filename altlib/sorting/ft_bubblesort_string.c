/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:02:33 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../strings/strings.h"

void	ft_bubblesort_strings(char **strings, int size)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (ft_strcmp(strings[j], strings[j + 1]) > 0)
			{
				tmp = strings[j];
				strings[j] = strings[j + 1];
				strings[j + 1] = tmp;
			}
			j++;
		}
		i++;
		j = 0;
	}
}
