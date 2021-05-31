/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 13:37:11 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H
# define GNL_BUFF_SIZE 4096
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct	s_vars
{
	size_t		buf;
	size_t		len;
	char		c;
	int			ret;
}				t_vars;

typedef struct	s_getc_vars
{
	char		tmp[GNL_BUFF_SIZE];
	int			i;
	int			len;
}				t_getc_vars;

void			ft_putstr(const char *const str);
size_t			ft_strlen(const char *str);
void			ft_strncpy(char *dest, const char *src, size_t size);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strcspn(const char *s, const char *reject);
char			*ft_strchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strclean(char *str);
char			*ft_strnext(char *str, bool reset);
char			*ft_strdup(const char *s);
int				get_next_line(const int fd, char **line);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putfloat(float n);
float			ft_atof(const char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);

#endif
