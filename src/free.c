/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:43:37 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/18 15:03:26 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_y)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	ft_free_game(t_game *game)
{
	printf("%p\n", game->win);
	printf("%p\n", game->mlx);
	printf("%p\n", game->img_player);
	printf("%p\n", game->img_empty_space);
	printf("%p\n", game->img_wall);
	printf("%p\n", game->img_collectible);
	printf("%p\n", game->img_exit);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
		// free(game->img_player);
	if (game->img_empty_space)
		mlx_destroy_image(game->mlx, game->img_empty_space);
		// free(game->img_empty_space);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
		// free(game->img_wall);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
		// free(game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
		// free(game->img_exit);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	// if (game->win)
	// 	free(game->win);
	if (game->map)
		ft_free_map(game);
	if (game->mlx)
		free(game->mlx);
	if (game)
		free(game);
}
