/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:31:15 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/11 18:34:43 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_window	win;
	t_game		game;
	// char		*path = "./assets/wall.xpm";
	// int			img_width;
	// int			img_height;
	// char		*texture;

	ft_error_check(&game, ac, av);
	ft_read_map(&game);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, (game.map_x * 64),
			(game.map_y * 64), "so_long");
	// put stuff to image
	// win.img = mlx_new_image(win.mlx, 64, 64);
	// ft_printf("x = %d, y = %d", game.map_x, game.map_y);
	// img_width = 64;
	// img_height = 64;
	// win.img = mlx_xpm_file_to_image(win.mlx, path, &img_width, &img_height);
	ft_make_image(&game, &win);
	// mlx_put_image_to_window(win.mlx, win.win, win.img, 0, 0);
	
	// mlx_string_put(win.mlx, win.win, 500, 500, 0x0000FF00, "Hello");
	mlx_hook(win.win, 2, 1L << 0, ft_key, &win);
	mlx_hook(win.win, 17, 0, ft_mouse, &win);
	mlx_loop(win.mlx);
	return (0);
}
