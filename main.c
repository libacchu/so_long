/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:46:22 by libacchu          #+#    #+#             */
/*   Updated: 2022/05/01 12:08:44 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	// t_window	win;
	t_game		game;

	if (ac != 2)
	{
		ft_putstr_fd("Error:\nInvalid input.\n", 1);
		// perror("Invalid input.");
		return (1);
	}
	game.map_path = av[1];
	ft_read_map(&game);
	// ft_printf("\n-----HERE-----\n");
	// win.mlx = mlx_init();
	// win.win = mlx_new_window(win.mlx, (game.map_x * 32),
	// 		(game.map_y * 32), "so_long");
	// mlx_loop(win.mlx);
	return (0);
}
