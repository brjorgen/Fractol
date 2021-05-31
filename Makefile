# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/10 00:40:57 by brjorgen          #+#    #+#              #
#    Updated: 2020/08/31 18:38:02 by brjorgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

_GREY=	$'\e[30m
_RED=	$'\e[31m
_GREEN=	$'\e[32m
_YELLOW=$'\e[33m
_BLUE=	$'\e[34m
_PURPLE=$'\e[35m
_CYAN=	$'\e[36m
_WHITE=	$'\e[37m

NAME 			= fractol

SRC_PATH		= 	.

SRC_NAME		=	draw_fractals.c 		\
				error_handler.c 			\
				events.c					\
				draw_hooks.c 			\
				images.c					\
				screen_init.c				\
				main.c 						\
				viewport.c					\
				threads.c					\
				images.c					\
				color.c						\
				palette.c					\
				mouse.c


OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra -Ofast

CPPFLAGS = -g -I includes -I altlib/ -I minilibx
CPPFLAGS_LINUX = -I/usr/include -Iincludes -I altlib/ -Iminilibx-linux
LDFLAGS = -Laltlib -I/usr/include
LINUX_LDLIBS = -lm -pthread -lbsd -lX11 -lXext minilibx-linux/libmlx.a altlib/altlib.a

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OS_NAME := $(shell uname -s | tr A-Z a-z)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[01;32mLet's go!!!\033[m"
	@echo "\033[01;33mCompiling Altlib...\033[m"
	@make -C minilibx-linux
	@make -C altlib
	@echo "Compilation of Altlib: \033[1;32mOK!\033[m"
	@echo "\033[01;33mCompiling Fractol...\033[m"
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $^ $(LINUX_LDLIBS)
	@echo "Compilation of Fract'ol:	\033[1;32mOK!\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $< -c $(CFLAGS) $(CPPFLAGS_LINUX) -o $@

clean:
	@make -C altlib clean
	@make -C minilibx-linux clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@echo "Fract'ol: Removing objs."

fclean: clean
	@make -C altlib fclean
	@rm -f $(NAME)
	@echo "Fract'ol: Removing executable."

re: fclean all

noaltlib: $(OBJ)
	@echo "\033[01;33mCompiling Fractol...\033[m"
	@echo "        😃\n     👊🏼/||\_ \n    _/¯    ¯\_\n"
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $(NAME)
	@echo "Compilation of Fract'ol:	\033[1;32mOK!\033[m"

.PHONY: all, clean, fclean, re, noaltlib
