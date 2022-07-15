/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:05:33 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/15 15:05:54 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_y)
	{
		ft_putstr_fd(game->map[i++], 1);
	}
	ft_printf("\nscore = %d\n", game->points);
	ft_printf("\ncollect = %d\n", game->amt_collectible);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);
}
