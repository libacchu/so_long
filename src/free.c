/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:43:37 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/22 21:57:03 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_img(void *mlx, void *ptr)
{
	if (ptr)
		mlx_destroy_image(mlx, ptr);
	ptr = NULL;
}

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

void	ft_free_mlx(void *mlx)
{
	mlx_destroy_display(mlx);
	mlx = 0;
}

void	ft_free_game_struct(t_game *game)
{
	free(game);
	game = 0;
}

void	ft_free_game(t_game *game)
{
	if (game->img_player)
		ft_free_img(game->mlx, game->img_player);
	if (game->img_empty_space)
		ft_free_img(game->mlx, game->img_empty_space);
	if (game->img_wall)
		ft_free_img(game->mlx, game->img_wall);
	if (game->img_collectible)
		ft_free_img(game->mlx, game->img_collectible);
	if (game->img_exit)
		ft_free_img(game->mlx, game->img_exit);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		ft_free_mlx(game->mlx);
	if (game->map)
		ft_free_map(game);
	if (game)
		ft_free_game_struct(game);
}
