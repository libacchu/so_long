/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:02:53 by libacchu          #+#    #+#             */
/*   Updated: 2022/04/24 18:56:17 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(int keystroke, t_window *win)
{
	if (keystroke == KEY_ESC)
	{
		mlx_destroy_window(win->mlx, win->win);
		exit (0);
	}
	return (0);
}

int	ft_close_win(int keycode, t_window *win)
{
	(void) keycode;
	mlx_destroy_window(win->mlx, win->win);
	exit (0);
	return (0);
}

int	ft_move_img(int keystroke, t_image *img)
{
	if (keystroke == KEY_W)
		img->y++;
	if (keystroke == KEY_S)
		img->y--;
	if (keystroke == KEY_D)
		img->x++;
	if (keystroke == KEY_A)
		img->x--;
	return (0);
}
