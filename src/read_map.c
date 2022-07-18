/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:10:57 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/18 12:54:42 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_fstandlst(char *line, t_mapc *check, t_game *game)
{
	int	count;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
	{
		if (line[count] != '1')
			return (1);
		check->m_wall = 1;
		count++;
	}
	if (count != game->map_x)
		return (1);
	return (0);
}

void	check_characters(char c, t_game *game, t_mapc *check)
{
	if (c == '0')
		check->m_spaces = 1;
	else if (c == 'C')
	{
		check->m_collectible = 1;
		game->amt_collectible++;
	}
	else if (c == 'E')
		check->m_exit = 1;
	else if (c == 'P')
		check->m_player++;
	else if (c == '1')
		check->m_wall = 1;
	else if (c == '\n' || c == '\0')
		check->m_newline = 1;
	else
		ft_exit("Error:\nInvalid map.\n", game, EXIT_FAILURE);
}

int	check_mid(char *line, t_mapc *check, t_game *game, int y)
{
	int	count;

	if (line[0] != '1' && line[game->map_x - 1] != '1')
		return (1);
	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
	{
		if (line[count] == 'P')
		{
			game->player_x = count;
			game->player_y = y;
		}
		check_characters(line[count], game, check);
		count++;
	}
	return (0);
}

void	ft_check_map_char(t_game *game)
{
	int		i;
	t_mapc	check;

	check = (t_mapc){};
	i = 0;
	while (i < game->map_y)
	{
		if (i == 0 || i == (game->map_y - 1))
		{
			if (check_fstandlst(game->map[i], &check, game))
				ft_exit("Error:\nInvalid map.\n", game, EXIT_FAILURE);
		}
		else
		{
			if (check_mid(game->map[i], &check, game, i))
				ft_exit("Error:\nInvalid map.\n", game, EXIT_FAILURE);
		}
		i++;
	}
	if (!check.m_spaces || !check.m_wall
		||!check.m_collectible || !check.m_exit
		|| !(check.m_player == 1))
		ft_exit("Error:\nInvalid map.\n", game, EXIT_FAILURE);
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
