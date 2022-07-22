# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 18:29:29 by libacchu          #+#    #+#              #
#    Updated: 2022/07/22 21:57:35 by libacchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

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

CC = gcc -Wall -Werror -Wextra
RM = rm -f

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a

MLX_DIR= ./minilibx/
MLX = ./minilibx/libmlx.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(SRCS)
	$(CC) $(SRCS) $(LIBFT) $(MLX) -L/usr/X11/lib -lXext -lX11 -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)
	
$(LIBFT):
	make -C $(LIBFT_DIR)
	
clean:
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: libft all mlx clean fclean re
