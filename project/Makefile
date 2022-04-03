# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 18:29:29 by libacchu          #+#    #+#              #
#    Updated: 2022/04/03 20:26:46 by libacchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c
OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = gcc -Wall -Werror -Wextra
RM = rm -f
PROGRAM = ./so_long

MAKE_MLX = make ./minilibx
RE_MLX = re ./minilibx
LMLX = -I /usr/X11/include -g -L/usr/X11/lib -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

%.o: %.c
	@$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LMLX) -o so_long
	
clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

run:
	$(PROGRAM)