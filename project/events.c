/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:02:53 by libacchu          #+#    #+#             */
/*   Updated: 2022/04/16 12:20:01 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int keystroke, t_window *win)
{
	if (keystroke == ON_ESC)
	{
		mlx_destroy_window(win->mlx, win->win);
		exit (0);
	}
	return (1);
}

int	ft_close_win(int keycode, t_window *win)
{
	(void) keycode;
	mlx_destroy_window(win->mlx, win->win);
	exit (0);
	return (0);
}
