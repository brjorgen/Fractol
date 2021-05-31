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

#ifndef BUFFERS_H
# define BUFFERS_H
# include <stdbool.h>
# include <stdlib.h>

# define BUFFSIZE 500

char	*buff_init(void);
size_t	buff_get_remainder(const char *buff_ptr);
bool	buff_write(char *buff_ptr, const char *data, const size_t size);
bool	buff_flush(char *buff_ptr);
void	buff_get_input(char *buff);

#endif
