/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:53:12 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/07 16:17:08 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_key(int keycode, t_window *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (EXIT_FAILURE);
	}
	if (keycode == KEY_W)
		ft_putstr_fd("W\n", 1);
	if (keycode == KEY_A)
		ft_putstr_fd("A\n", 1);
	if (keycode == KEY_S)
		ft_putstr_fd("S\n", 1);
	if (keycode == KEY_D)
		ft_putstr_fd("D\n", 1);
	return (0);
}

int	ft_mouse(t_window *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (EXIT_FAILURE);
}
