# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalic <asalic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 16:11:40 by asalic            #+#    #+#              #
#    Updated: 2023/06/20 13:54:39 by asalic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

COMP = gcc -c $(CFLAGS)

SRC = ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnb.c \
	ft_putunb.c \
	ft_printhexa.c \
	ft_addrhexa.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all : $(NAME)

$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(OBJ_DIR)
	@$(COMP) $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean :
	@rm -rf $(OBJ) $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean
	@make all

.PHONY : all clean fclean re
