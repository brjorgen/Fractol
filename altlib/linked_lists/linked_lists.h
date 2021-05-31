/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/24 17:51:54 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LISTS_H
# define LINKED_LISTS_H
# include <stdbool.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*data;
	size_t			size;
	struct s_list	*next;
}					t_list;

typedef enum		e_sort_type
{
	CUSTOM_CMP,
	STR_CMP,
	NUM_CMP
}					t_e_sort_type;

t_list				*list_init_list(void *data, size_t size);
t_list				*array_to_list(void **array, size_t size);
size_t				list_len(t_list *head);
void				list_print(t_list *head);
bool				list_add_end(t_list *head, t_list *tail);
bool				list_add_front(t_list **head, t_list *new_head);
bool				list_delete_link(t_list *link);
bool				list_delete_list(t_list *head);
void				list_sort(t_list *list, t_e_sort_type sort_type,
	bool (*custom_cmp_function)(t_list *, t_list *));
t_list				*list_copy(t_list *list_head,
	bool (*predicate_stop_condition_function)(t_list *));
t_list				*list_find(t_list *list_head,
	bool (*predicate_match_function)(t_list *));

#endif
