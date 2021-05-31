/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:34:39 by brjorgen          #+#    #+#             */
/*   Updated: 2020/08/31 18:03:20 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H
# include "./fractol.h"
# define THREADS 		8

typedef struct s_env	t_env;

typedef struct		s_thread
{
	int		id;
	t_env	*env;
}					t_thread;

typedef struct		s_render
{
	pthread_t	threads[THREADS];
	t_thread	args[THREADS];
}					t_render;

#endif
