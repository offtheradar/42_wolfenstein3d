# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/05 18:58:39 by ysibous           #+#    #+#              #
#    Updated: 2018/05/07 19:36:57 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wold3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o
FRAMEW = -framework OpenGL -framework Appkit

FILES = main.c
FILES += load_file.c
FILES += compute_distances_dda.c
FILES += draw_wall.c
FILES += init_wolf_struct.c
FILES += move_player.c

SRC = $(addprefix src/, $(FILES))

all: $(NAME)

re: fclean all

clean:
		rm -rf build

fclean: clean
		rm -rf $(NAME)
		
MLIBX = includes/minilibx/libmlx.a

LIBFT = includes/libft/libft.a

LIBGFX = includes/libgfx/libgfx.a

mlibft.a: 
		make -C includes -C libft re

mlibgfx.a: 
		make -C includes -C libgfx re

mlibx.a: 
		make -C includes -C minilibx re

$(NAME): mlibft.a mlibgfx.a mlibx.a
	$(CC) $(CFLAGS) $(NAME) $(SRC) $(LIBFT) $(LIBGFX) $(LIBX) $(MLIBX) $(FRAMEW)