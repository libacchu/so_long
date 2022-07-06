/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:10:57 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/06 13:01:07 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_checkfile_end(t_game *game)
{
	char	*ending;
	int		i;

	ending = ft_strrchr(game->map_path, '.');
	if (!ending || ft_strlen(ending) != 4)
	{	
		ft_putstr_fd("Error:\nInvalid map file.\n", 1);
		exit (0);
	}
	else
	{
		i = 0;
		while (ending[i] != '\0')
		{
			if (ending[i] != ".ber"[i])
			{
				ft_putstr_fd("Error:\nInvalid map file.\n", 1);
				exit (0);
			}
			i++;
		}
	}
}

void	ft_checkline_len(char *line, size_t fst_len)
{
	size_t	len;

	len = ft_strlen(line);
	if (ft_strchr(line, '\n'))
		len -= 1;
	if (len != fst_len)
	{
		ft_putstr_fd("Error:\nInvalid map size.\n", 1);
		exit (0);
	}
}

int	ft_numoflines(t_game *game)
{
	char		*line;
	int			fd;
	size_t		line_len;

	fd = open(game->map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line || !fd || fd < 0)
	{
		perror("Error");
		exit (0);
	}
	line_len = ft_strlen(line) - 1;
	game->map_y = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
			ft_checkline_len(line, line_len);
		game->map_y++;
	}
	free(line);
	close(fd);
	return (game->map_y);
}

void	ft_check_map_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] && i < game->map_y)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == (game->map_y - 1))
			{
				if (game->map[i][j] != '1' && game->map[i][j] != '\n')
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
				game->mapc->m_spaces = 1;
			else if (game->map[i][j] == '1')
				game->mapc->m_wall = 1;
			else if (game->map[i][j] == 'C')
				game->mapc->m_collectible = 1;
			else if (game->map[i][j] == 'E')
				game->mapc->m_exit = 1;
			else if (game->map[i][j] == 'P')
				game->mapc->m_player++;
			else
			{
				ft_putstr_fd("Error:\nInvalid map.\n", 1);
				exit (0);
			}
			ft_printf("\n----------HERE----------\n");
			j++;
		}
		i++;
	}
	if (!game->mapc->m_spaces || !game->mapc->m_wall
		||!game->mapc->m_collectible || !game->mapc->m_exit
		|| game->mapc->m_player > 1 || !game->mapc->m_player)
	{
		ft_putstr_fd("Error:\nInvalid map.\n", 1);
		exit (0);
	}
	// i = 0;
	// while (line[i])
	// {
	// 	if (ft_strchr(&line[i], '0'))
	// 		game->mapc->m_spaces = 1;
	// 	else if (ft_strchr(&line[i], '1'))
	// 		game->mapc->m_wall = 1;
	// 	else if (ft_strchr(&line[i], 'C'))
	// 		game->mapc->m_collectible = 1;
	// 	else if (ft_strchr(&line[i], 'E'))
	// 		game->mapc->m_exit = 1;
	// 	else if (ft_strchr(&line[i], 'P'))
	// 		game->mapc->m_player = 1;
	// 	else
	// 	{
	// 		ft_putstr_fd("Error:\nInvalid map.\n", 1);
	// 		free(game->map);
	// 		exit (0);
	// 	}
	// 	i++;
	// }
}

void	ft_read_map(t_game *game)
{
	int	fd;
	int	i;

	ft_checkfile_end(game);
	ft_numoflines(game);
	fd = open(game->map_path, O_RDONLY);
	game->map = (char **)malloc(11 * sizeof(char *));
	i = 0;
	while (i < game->map_y)
	{
		game->map[i] = get_next_line(fd);
		// ft_printf("%s", game->map[i]);
		i++;
	}
	game->map_x = ft_strlen(game->map[i - 1]);
	close(fd);
	ft_check_map_char(game);
}
