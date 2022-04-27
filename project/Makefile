# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 18:29:29 by libacchu          #+#    #+#              #
#    Updated: 2022/04/27 12:14:56 by libacchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c \
		./src/rectangle.c \
		./src/colors.c \
		./src/events.c \
		./src/read_map.c \
		
OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = gcc -Wall -Werror -Wextra
RM = rm -f
PROGRAM = ./so_long

LIBFT = libft.a
MAKE_LIBFT = make re -C ./libft
CLEAN_LIBFT = make clean -C ./libft/
FLCEAN_LIBFT = make fclean -C ./libft/
RE_LIBFT = make re -C ./libft/

MAKE_MLX = make ./minilibx
RE_MLX = re ./minilibx
# LMLX = -I /usr/X11/include -g -L/usr/X11/lib -lmlx -framework OpenGL -framework AppKit
LMLX = -I /usr/X11/include -g -lmlx -framework OpenGL -framework AppKit


all: $(NAME) $(LIBFT)

$(LIBFT):
	@$(MAKE_LIBFT)
	@cp libft/libft.a .
	
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(LMLX) $(LIBFT) -o so_long

%.o: %.c
	@$(CC) -Imlx -c $< -o $@
	
clean:
	@$(CLEAN_LIBFT)
	@$(RM) $(OBJS)

fclean: clean
	@$(FLCEAN_LIBFT)
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)

re: fclean all

run:
	$(PROGRAM)