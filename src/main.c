/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:31:15 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/07 16:38:46 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_window	win;
	t_game		game;

	ft_error_check(&game, ac, av);
	ft_read_map(&game);
	// win.img = mlx_new_image(win.mlx, 1920, 1080);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, (game.map_x * 32),
			(game.map_y * 32), "so_long");
	// put stuff to image
	// mlx_put_image_to_window(win.mlx, win.win, win.img, 0, 0);
	mlx_string_put(win.mlx, win.win, 500, 500, 0x0000FF00, "Hello");
	mlx_hook(win.win, 2, 1L << 0, ft_key, &win);
	mlx_hook(win.win, 17, 0, ft_mouse, &win);
	mlx_loop(win.mlx);
	ft_putstr_fd("----------HERE----------\n", 1);
	return (0);
}
