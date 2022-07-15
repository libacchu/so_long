/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:53:12 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/15 13:00:02 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		ft_exit(NULL, game, EXIT_SUCCESS);
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

int	ft_mouse(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_exit(NULL, game, EXIT_SUCCESS);
	return (0);
}
