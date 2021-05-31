/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 23:22:30 by brjorgen          #+#    #+#             */
/*   Updated: 2020/08/31 18:03:10 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_handler(char *err_str, int halt)
{
	ft_putstr(err_str);
	if (halt == 1)
	{
		ft_putstr("== program halted ==\n");
		exit(EXIT_FAILURE);
	}
}
