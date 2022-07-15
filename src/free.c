/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:43:37 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/15 15:47:31 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	ft_printf("----HERE----\n");
	while (i < game->map_y)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	ft_free_game(t_game *game)
{
	if (game->mlx)
		free(game->mlx);
	if (game->win)
		free(game->win);
	if (game->img_player)
		free(game->img_player);
	if (game->img_empty_space)
		free(game->img_empty_space);
	if (game->img_wall)
		free(game->img_wall);
	if (game->img_collectible)
		free(game->img_collectible);
	if (game->img_exit)
		free(game->img_exit);
	// ft_printf("game->map_path = %s\n", game->map);
	// if (game->map_path)
	// 	free(game->map_path);
	if (game->map)
		ft_free_map(game);
	if (game)
		free(game);
	// (void) game;
}
