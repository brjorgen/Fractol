/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:05:17 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../altlib.h"
#include "math.h"

int	ft_bin_search_int(int *array, int target, int array_size)
{
	int mid;
	int left;
	int right;

	left = 0;
	right = array_size - 1;
	while (left <= right)
	{
		mid = floor((left + right) / 2);
		if (array[mid] == target)
			return (mid);
		if (array[mid] < target)
			left = mid + 1;
		if (array[mid] > target)
			right = mid - 1;
	}
	return (-1);
}

int	ft_bin_search_str(char **array, char *target, int array_size)
{
	int mid;
	int left;
	int right;
	int diff;

	left = 0;
	right = array_size - 1;
	while (left <= right)
	{
		mid = floor((left + right) / 2);
		diff = ft_strcmp(array[mid], target);
		if (diff == 0)
			return (mid);
		if (diff < 0)
		{
			left = mid + 1;
		}
		if (diff > 0)
		{
			right = mid - 1;
		}
	}
	return (-1);
}
