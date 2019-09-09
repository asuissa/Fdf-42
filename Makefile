# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuissa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 17:36:49 by asuissa           #+#    #+#              #
#    Updated: 2018/03/07 21:39:08 by asuissa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
.SUFFIXES:

# couleurs
RED = \x1B[31m
GREEN = \x1B[32m
YELLOW = \x1B[33m
BLUE = \x1B[34m
PURPLE = \x1B[35m
RESET = \033[0m
HEAD = \033[H\033[2J

MLX = -L minilibx -lmlx -framework OpenGL -framework Appkit

CC = gcc
NAME = fdf
CFLAGS = -Wall -Wextra -Werror
HEADER = fdf.h
CPPFLAGS = -I $(INCLUDE)
OBJ = $(FILES:.c=.o)
CLIBFT = -L libft -lft
SRC_PATH = src/
INC_PATH = inc/
INCLUDE = $(addprefix $(INC_PATH), $(HEADER))
SRC = $(addprefix $(SRC_PATH), $(FILES))
FILES = \
			fdf.c \
			ft_events.c\
			map_dimension.c\
			fill_image.c\
			calc_coord.c\

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@make -C minilibx
	@printf "\r\e[K[$(YELLOW)Make .o done$(RESET)]\n"
	@$(CC) $(CFLAGS) $(CLIBFT) $(MLX) $^ -o $@
	@echo "[$(PURPLE)Make $(NAME) done$(RESET)]"

%.o: $(SRC_PATH)%.c
	@$(CC) -c $(CFLAGS) $< -o $@ $(CPPFLAGS)
	@printf "\r\e[K[$(YELLOW)Make $@ done$(RESET)]"

clean :
	@make -C libft clean
	@make -C minilibx clean
	@/bin/rm -f $(OBJ)
	@echo "[$(RED)Clean .o done$(RESET)]"

fclean : clean
	@make -C libft fclean
	@make -C minilibx fclean
	@/bin/rm -f $(NAME)
	@echo "[$(RED)Clean $(NAME) done$(RESET)]"

re : fclean all

norme :
	@make -C libft norme
	@norminette $(SRC) $(INCLUDE)
