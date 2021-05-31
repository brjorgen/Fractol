/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:01:52 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/11 01:27:12 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*ca;
	unsigned char	*cb;

	ca = (unsigned char *)s1;
	cb = (unsigned char *)s2;
	i = 0;
	if (!(ca || cb))
		return (0);
	while ((ca[i] && cb[i]) && (ca[i] == cb[i]))
		i++;
	return (ca[i] - cb[i]);
}
