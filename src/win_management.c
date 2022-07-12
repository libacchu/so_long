/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:53:12 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/12 16:24:09 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '0')
	{
		game->player_x++;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, (game->player_x * 64), (game->player_y * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty_space, ((game->player_x - 1) * 64), (game->player_y * 64));
	}
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] == '0')
	{
		game->player_x--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, (game->player_x * 64), (game->player_y * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty_space, ((game->player_x + 1) * 64), (game->player_y * 64));
	}
}

void	ft_move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '0')
	{
		game->player_y--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->player_x * 64, (game->player_y * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty_space, game->player_x * 64, (game->player_y + 1) * 64);
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '0')
	{
		game->player_y++;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->player_x * 64, (game->player_y * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty_space, game->player_x * 64, (game->player_y - 1) * 64);
	}
}

int	ft_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit (EXIT_FAILURE);
	}
	if (keycode == KEY_W)
		ft_move_up(game);
	if (keycode == KEY_A)
		ft_move_left(game);
	if (keycode == KEY_S)
		ft_move_down(game);
	if (keycode == KEY_D)
		ft_move_right(game);
	return (0);
}

int	ft_mouse(t_window *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (EXIT_FAILURE);
}
