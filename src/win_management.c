/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:53:12 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/14 00:04:07 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
