/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:12:06 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/15 15:51:40 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
**	ft_exit() write an error message, frees any variable that was allocated space
** 	and then exits the program.
**
**	char *err_mess: The error message to be printed to the screen.
**	t_game *game: 	Struct to be freed.
**	int ex_num: 	Exit Number.
*/

void	ft_exit(char *err_mess, t_game *game, int ex_num)
{
	if (err_mess)
		ft_putstr_fd(err_mess, 1);
	// if (game->mlx && game->win)
	// 	mlx_destroy_window(game->mlx, game->win);
	if (game)
		ft_free_game(game);
	// game = NULL;
	exit (ex_num);
}
