/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:02:53 by libacchu          #+#    #+#             */
/*   Updated: 2022/04/15 23:55:07 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int keystroke, t_window *win)
{
	if (keystroke == 53)
	{
		mlx_destroy_window(win->mlx, win->win);
		exit (0);
	}
	return (1);
}
