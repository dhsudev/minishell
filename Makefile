# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 21:20:48 by ltrevin-          #+#    #+#              #
#    Updated: 2024/11/19 11:58:56 by ltrevin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= minishell
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address

LIBS 			= -lreadline -Linc/libft -lft
INCLUDE 		= -Iinc 
HEADER			= inc/minishell.h

SRC_DIR 		= src/
OBJ_DIR 		= obj/
SRC 			:=	main.c clean_utils.c env.c\
					builtins/echo.c \
					tokenizer/tokenizer.c tokenizer/token_type.c tokenizer/error_mng.c\
					executor/executor.c executor/cmd_list.c executor/path_search.c\
					expansor/expansor.c expansor/expansor_utils.c\
					init_data.c	print_utils.c \
					#prep_exec/prep_exec.c					
SRC				:= $(addprefix $(SRC_DIR), $(SRC))
OBJ				= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all : $(NAME)

re : fclean all

$(NAME) : $(OBJ) | libft
	echo $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c  $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(OBJ_DIR)/builtins $(OBJ_DIR)/tokenizer \
	$(OBJ_DIR)/expansor $(OBJ_DIR)/executor $(OBJ_DIR)/prep_exec

libft:
	@$(MAKE) -C inc/libft --no-print-directory


clean :
	rm -rf $(OBJ_DIR)

fclean : clean 
	@$(MAKE) -C inc/libft fclean --no-print-directory
	rm -f $(NAME)

test : 

.PHONY : all clean fclean re
