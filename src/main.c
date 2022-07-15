/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:31:15 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/15 15:39:33 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	*ft_init(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->player_x = 0;
	game->player_y = 0;
	game->map_x = 0;
	game->map_y = 0;
	game->x = 0;
	game->y = 0;
	game->points = 0;
	game->amt_collectible = 0;
	game->amt_of_moves = 0;
	game->flag = 0;
	return (game);
}

int	main(int ac, char **av)
{
	t_game		*game;

	game = ft_init();
	ft_error_check(game, ac, av);
	ft_read_map(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->map_x * 64),
			(game->map_y * 64), "so_long");
	ft_make_image(game);
	mlx_hook(game->win, 2, 1L << 0, ft_key, game);
	mlx_hook(game->win, 17, 0, ft_mouse, game);
	mlx_loop(game->mlx);
	return (0);
}
