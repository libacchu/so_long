/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:53:12 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/12 21:50:05 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_y)
	{
		ft_putstr_fd(game->map[i++], 1);
	}
	ft_printf("\nscore = %d\n", game->points);
	ft_printf("\ncollect = %d\n", game->amt_collectible);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);
}

void	ft_move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '0' ||
		game->map[game->player_y][game->player_x + 1] == 'C')
	{
		game->player_x++;
		if (game->map[game->player_y][game->player_x] == 'C')
			game->points++;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, (game->player_x * 64), (game->player_y * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty_space, ((game->player_x - 1) * 64), (game->player_y * 64));
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x - 1] = '0';
	}
	if (game->map[game->player_y][game->player_x] == 'E' && game->points == game->amt_collectible)
		exit (0);
	print_map(game);
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] == '0' || game->map[game->player_y][game->player_x - 1] == 'C')
	{
		game->player_x--;
		if (game->map[game->player_y][game->player_x] == 'C')
			game->points++;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x + 1] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, (game->player_x * 64), (game->player_y * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty_space, ((game->player_x + 1) * 64), (game->player_y * 64));
	}
	if (game->map[game->player_y][game->player_x] == 'E' && game->points == game->amt_collectible)
		exit(0);
	print_map(game);
}

void	ft_move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '0' || game->map[game->player_y - 1][game->player_x] == 'C')
	{
		game->player_y--;
		if (game->map[game->player_y][game->player_x] == 'C')
			game->points++;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y + 1][game->player_x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->player_x * 64, (game->player_y * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty_space, game->player_x * 64, (game->player_y + 1) * 64);
	}
	if (game->map[game->player_y][game->player_x] == 'E' && game->points == game->amt_collectible)
		exit(0);
	print_map(game);
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '0' || game->map[game->player_y + 1][game->player_x] == 'C')
	{
		game->player_y++;
		if (game->map[game->player_y][game->player_x] == 'C')
			game->points++;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y - 1][game->player_x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->player_x * 64, (game->player_y * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty_space, game->player_x * 64, (game->player_y - 1) * 64);
	}
	if (game->map[game->player_y][game->player_x] == 'E' && game->points == game->amt_collectible)
		exit(0);
	print_map(game);
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
