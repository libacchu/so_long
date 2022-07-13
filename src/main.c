/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:31:15 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/13 13:54:48 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game		game;

	game = (t_game){};
	ft_error_check(&game, ac, av);
	ft_read_map(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (game.map_x * 64),
			(game.map_y * 64), "so_long");
	ft_make_image(&game);
	mlx_hook(game.win, 2, 1L << 0, ft_key, &game);
	mlx_hook(game.win, 17, 0, ft_mouse, &game);
	mlx_loop(game.mlx);
	return (0);
}
