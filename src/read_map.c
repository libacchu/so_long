/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:10:57 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/12 15:34:46 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_map_char(t_game *game)
{
	int		i;
	int		j;
	t_mapc	check;

	i = 0;
	check.m_player = 0;
	while (game->map[i] && i < game->map_y)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (j == 0 || j == (game->map_x - 1))
			{
				if (game->map[i][j] != '1')
				{
					ft_putstr_fd("Error:\nInvalid map.\n", 1);
					exit (0);
				}
			}
			if ((j == 0 || j == (game->map_x - 1))
				&& (game->map[i][j] != '1'))
			{
				ft_putstr_fd("Error:\nInvalid map.\n", 1);
				exit (0);
			}
			if (game->map[i][j] == '0')
				check.m_spaces = 1;
			else if (game->map[i][j] == '1')
				check.m_wall = 1;
			else if (game->map[i][j] == 'C')
				check.m_collectible = 1;
			else if (game->map[i][j] == 'E')
				check.m_exit = 1;
			else if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				check.m_player++;
			}
			else if (game->map[i][j] == '\n' || game->map[i][j] == '\0')
				check.m_newline = 1;
			else
			{
				ft_putstr_fd("Error:\nInvalid map.\n", 1);
				exit (0);
			}
			j++;
		}
		i++;
	}
	if (!check.m_spaces || !check.m_wall
		||!check.m_collectible || !check.m_exit
		|| !(check.m_player == 1))
	{
		ft_putstr_fd("Error:\nInvalid map.\n", 1);
		exit (0);
	}
}

void	ft_read_map(t_game *game)
{
	int	fd;
	int	i;

	fd = open(game->map_path, O_RDONLY);
	game->map = (char **)malloc(game->map_y * sizeof(char *));
	i = 0;
	while (i < game->map_y)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	game->map_x = ft_strlen(game->map[i - 1]);
	close(fd);
	ft_check_map_char(game);
}
