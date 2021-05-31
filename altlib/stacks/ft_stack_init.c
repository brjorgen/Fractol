/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:59:01 by brjorgen          #+#    #+#             */
/*   Updated: 2019/11/11 20:59:53 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stacks.h"
#include "../mem/mem.h"

int	ft_init_stack(t_stack *stack, const size_t size)
{
	if (!size || !(stack->data = (void *)malloc(size)))
		return (-1);
	ft_bzero(stack->data, size * sizeof(*stack->data));
	stack->size = size;
	stack->top_index = 0;
	return (1);
}
