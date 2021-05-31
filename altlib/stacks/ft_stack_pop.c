/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:00:32 by brjorgen          #+#    #+#             */
/*   Updated: 2019/11/11 21:00:34 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stacks.h"

int	ft_stack_pop(t_stack *stack)
{
	if (ft_stack_empty_p(*stack))
		return (-1);
	stack->top_index--;
	return (((int *)stack->data)[stack->top_index + 1]);
}
