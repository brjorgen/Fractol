#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 17:44:13 by brjorgen          #+#    #+#              #
#    Updated: 2020/11/25 08:27:39 by crenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PURPLE	=	\033[35m
TUR		=	\033[36m
WHITE	=	\033[37m
END		=	\033[0m

NAME	=	altlib.a

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g

SRCS	=	./hash_maps/hash_data.c			\
		./hash_maps/hashmap_destroy_hashmap.c	\
		./hash_maps/hashmap_get_elem.c		\
		./hash_maps/hashmap_init.c		\
		./hash_maps/hashmap_init_elem.c		\
		./hash_maps/hashmap_insert_elem.c	\
		./hash_maps/hashmap_traverse_list.c	\
		./linked_lists/list_add_end.c		\
		./linked_lists/list_add_front.c		\
		./linked_lists/list_delete_link.c	\
		./linked_lists/list_delete_list.c	\
		./linked_lists/list_init.c		\
		./linked_lists/list_len.c		\
		./linked_lists/list_print.c		\
		./stacks/ft_stack_pop.c			\
		./stacks/ft_stack_push.c		\
		./stacks/ft_stack_empty_p.c		\
		./stacks/ft_stack_init.c		\
		./buffers/buff_flush.c			\
		./buffers/buff_get_input.c		\
		./buffers/buff_get_remainder.c		\
		./buffers/buff_init.c			\
		./buffers/buff_write.c			\
		./mem/ft_bzero.c			\
		./mem/ft_memcmp.c			\
		./mem/ft_memcpy.c			\
		./mem/ft_memdup.c			\
		./mem/ft_memset.c			\
		./strings/ft_putstr.c			\
		./strings/ft_strchr.c			\
		./strings/ft_strcmp.c			\
		./strings/ft_strcspn.c			\
		./strings/ft_strlen.c			\
		./strings/ft_strncpy.c			\
		./strings/ft_strstr.c			\
		./strings/ft_strclean.c			\
		./strings/ft_strnext.c			\
		./strings/ft_strdup.c			\
		./strings/ft_get_next_line.c		\
		./strings/ft_putchar.c			\
		./strings/ft_putnbr.c			\
		./strings/ft_putfloat.c			\
		./strings/ft_atoi.c			\
		./strings/ft_itoa.c			\
		./strings/ft_atof.c			\
		./search/ft_bin_search.c		\
		./sorting/ft_bubblesort_string.c	\
		./sorting/ft_swap.c	\
		./sorting/ft_bubblesort_int.c

OBJ	=	$(SRCS:%.c=%.o)

HEADER	=	altlib.h

%.o	:	%.c $(HEADER)
		@$(CC) -o $@ -c $< $(CFLAGS)

all	:	$(NAME)

$(NAME) :	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "${BLUE}Altlib: compiled static library.${END}"

clean	:
		@rm -rf $(OBJ)
		@echo "${RED}Altlib: removed object files.${END}"

fclean	:	clean
		@rm -rf $(NAME)
		@echo "${RED}Altlib: removed static library.${END}"

re	:	fclean all
