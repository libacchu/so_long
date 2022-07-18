/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:41:15 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/18 21:51:53 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*map_char(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
		return (game->img_player);
	if (game->map[i][j] == '0')
		return (game->img_empty_space);
	if (game->map[i][j] == 'C')
		return (game->img_collectible);
	if (game->map[i][j] == 'E')
		return (game->img_exit);
	if (game->map[i][j] == '1')
		return (game->img_wall);
	return (NULL);
}

void	put_to_screen(t_game *game)
{
	int		i;
	int		j;
	void	*tmp;

	i = 0;
	while (i < game->map_y)
	{
		j = 0;
		while (j < game->map_x)
		{
			tmp = map_char(game, i, j);
			mlx_put_image_to_window(game->mlx,
				game->win, tmp, (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}

void	ft_make_image(t_game *game)
{
	make_player(game);
	make_empty_space(game);
	make_wall(game);
	make_collectible(game);
	make_exit(game);
	put_to_screen(game);
}
