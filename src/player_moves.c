/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:00:35 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/15 15:05:07 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



void	ft_move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == 'E' &&
		game->points == game->amt_collectible)
	{
		ft_exit(">>SUCCESS<<\n", game, EXIT_SUCCESS);
	}
	if (game->map[game->player_y][game->player_x + 1] == '0' ||
		game->map[game->player_y][game->player_x + 1] == 'C')
	{
		game->player_x++;
		ft_printf("moves = %d\n", game->amt_of_moves++);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->points++;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			(game->player_x * 64), (game->player_y * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty_space,
			((game->player_x - 1) * 64), (game->player_y * 64));
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x - 1] = '0';
	}
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] == 'E' &&
		game->points == game->amt_collectible)
	{
		ft_exit(">>SUCCESS<<\n", game, EXIT_SUCCESS);
	}
	if (game->map[game->player_y][game->player_x - 1] == '0' ||
		game->map[game->player_y][game->player_x - 1] == 'C')
	{
		game->player_x--;
		ft_printf("moves = %d\n", game->amt_of_moves++);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->points++;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x + 1] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			(game->player_x * 64), (game->player_y * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty_space,
			((game->player_x + 1) * 64), (game->player_y * 64));
	}
}

void	ft_move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == 'E' &&
		game->points == game->amt_collectible)
	{
		ft_exit(">>SUCCESS<<\n", game, EXIT_SUCCESS);
	}
	if (game->map[game->player_y - 1][game->player_x] == '0' ||
		game->map[game->player_y - 1][game->player_x] == 'C')
	{
		game->player_y--;
		ft_printf("moves = %d\n", game->amt_of_moves++);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->points++;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y + 1][game->player_x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->player_x * 64, (game->player_y * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty_space,
			game->player_x * 64, (game->player_y + 1) * 64);
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == 'E' &&
		game->points == game->amt_collectible)
	{
		ft_exit(">>SUCCESS<<\n", game, EXIT_SUCCESS);
	}
	if (game->map[game->player_y + 1][game->player_x] == '0' ||
		game->map[game->player_y + 1][game->player_x] == 'C')
	{
		game->player_y++;
		ft_printf("moves = %d\n", game->amt_of_moves++);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->points++;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y - 1][game->player_x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->player_x * 64, (game->player_y * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty_space,
			game->player_x * 64, (game->player_y - 1) * 64);
	}
}
