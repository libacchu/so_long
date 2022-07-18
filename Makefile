# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 18:29:29 by libacchu          #+#    #+#              #
#    Updated: 2022/07/18 15:16:08 by libacchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	./src/main.c \
		./src/read_map.c \
		./src/error_check.c \
		./src/free.c \
		./src/win_management.c \
		./src/image.c \
		./src/exit.c \
		./src/file_to_image.c \
		./src/player_moves.c \
		./src/print_map.c \

OBJS = $(SRCS:.c=.o)
INCLUDE = ./include/
NAME = so_long

CC = gcc -Wall -Werror -Wextra -g -Og
RM = rm -f

LIBFT = ./libft/libft.a
LIBFT_DIR = libft/

MLX = ./minilibx-linux/libmlx.a
MLX_DIR= ./minilibx-linux/

all: $(NAME)

libft:
	make -C $(LIBFT_DIR)

mlx:
	make -C $(MLX_DIR)

$(NAME): $(OBJS) libft mlx
	# make -C $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(MLX) -L/usr/X11/lib -lXext -lX11 -o $(NAME)

# -framework OpenGL -framework AppKit

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: libft all mlx clean fclean re
