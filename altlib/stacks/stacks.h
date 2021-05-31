/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:13:57 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H
# include "../altlib.h"

typedef struct	s_stack
{
	void		*data;
	size_t		size;
	size_t		top_index;
}				t_stack;

int				ft_init_stack(t_stack *stack, const size_t size);
int				ft_stack_empty_p(const t_stack stack);
int				ft_stack_push(t_stack *stack, int data_to_push);
int				ft_stack_pop(t_stack *stack);

#endif
