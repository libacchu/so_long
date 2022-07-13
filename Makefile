# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 18:29:29 by libacchu          #+#    #+#              #
#    Updated: 2022/07/14 01:27:18 by libacchu         ###   ########.fr        #
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

OBJS = $(SRCS:.c=.o)
INCLUDE = ./include/
NAME = so_long

CC = gcc -Wall -Werror -Wextra
RM = rm -f

LIBFT = libft/

MLX = ./minilibx_opengl/

# LMLX = -I /usr/X11/include -g -L/usr/X11/lib -lmlx -framework OpenGL -framework AppKit
# LMLX = -I /usr/X11/include -g -lmlx -framework OpenGL -framework AppKit
# LMLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

# all: libft $(NAME)
all: libft mlx $(NAME)

libft:
	make -C $(LIBFT)

mlx:
	make -C $(MLX)

$(NAME): $(OBJS) libft mlx
	# make -C $(LIBFT)
	$(CC) $(OBJS) ./libft/libft.a ./minilibx_opengl/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

# %.o: %.c
# 	@$(CC) -Imlx -c $< -o $@

clean:
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	@$(RM) $(NAME)

re: fclean all

.PHONY: libft all mlx clean fclean re