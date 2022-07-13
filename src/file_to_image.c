/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 23:01:32 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/14 00:03:32 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	make_player(t_game *game)
{
	int	x;
	int	y;

	game->img_player = mlx_xpm_file_to_image(game->mlx, MAP_PLAYER, &x, &y);
}

void	make_empty_space(t_game *game)
{
	int	x;
	int	y;

	game->img_empty_space = mlx_xpm_file_to_image(game->mlx,
			MAP_EMPTY_SPACE, &x, &y);
}

void	make_wall(t_game *game)
{
	int	x;
	int	y;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, MAP_WALLS, &x, &y);
}

void	make_collectible(t_game *game)
{
	int	x;
	int	y;

	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			MAP_COLLECT, &x, &y);
}

void	make_exit(t_game *game)
{
	int	x;
	int	y;

	game->img_exit = mlx_xpm_file_to_image(game->mlx, MAP_EXIT, &x, &y);
}
