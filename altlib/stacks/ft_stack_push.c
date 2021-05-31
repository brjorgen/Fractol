/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:00:53 by brjorgen          #+#    #+#             */
/*   Updated: 2020/02/22 23:36:33 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stacks.h"

int	ft_stack_push(t_stack *stack, int data_to_push)
{
	if ((stack->top_index + 1) > stack->size)
		return (-1);
	stack->top_index++;
	((int *)stack->data)[stack->top_index] = data_to_push;
	return (1);
}
