/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:55:53 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H
# include <stdlib.h>
# include <stdint.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *mem, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memdup(const void *data, const size_t size);
void	ft_memset(void *data, int c, size_t n);

#endif
