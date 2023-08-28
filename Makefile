# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalic <asalic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:43:29 by asalic            #+#    #+#              #
#    Updated: 2023/06/21 14:13:44 by asalic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC_S = server
EXEC_C = client
PATHPRINTF = libftprintf/libftprintf.a
INCLUDE = libftprintf/libftprintf.h minitalk.h
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_S = server.c utils.c
SRC_C = client.c utils.c

OBJDIR_C = obj_client
OBJDIR_S = obj_server
OBJ_C = $(addprefix $(OBJDIR_C)/,$(SRC_C:%.c=%.o))
OBJ_S = $(addprefix $(OBJDIR_S)/,$(SRC_S:%.c=%.o))

all : $(PATHPRINTF) $(EXEC_S) $(EXEC_C) $(INCLUDE)

$(OBJDIR_C)/%.o:%.c
	@mkdir -p $(OBJDIR_C)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_S)/%.o:%.c
	@mkdir -p $(OBJDIR_S)
	@$(CC) $(CFLAGS) -c $< -o $@

$(EXEC_C) : $(PATHPRINTF) $(OBJ_C)
	@$(CC) $(CFLAGS) -o $(EXEC_C) $(OBJ_C) -Llibftprintf -lftprintf
	@echo "----Exec client created----\n"
	
$(EXEC_S) : $(PATHPRINTF) $(OBJ_S)
	@$(CC) $(CFLAGS) -o $(EXEC_S) $(OBJ_S) -Llibftprintf -lftprintf
	@echo "----Exec server created----\n"

$(PATHPRINTF) :
	@make -s -C libftprintf 

clean :
	@rm -rf $(OBJDIR_C) $(OBJDIR_S) $(OBJ_C) $(OBJ_S)
	@make -s clean -C libftprintf
	@echo "----Clean done----\n"

fclean : clean
	@rm -rf $(EXEC_S) $(EXEC_C)
	@make -s fclean -C libftprintf
	@echo "----Fclean done----\n"

re : fclean
	@make -s all

.PHONY : all clean fclean re
