/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:35:25 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/22 22:12:51 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_checkline_len(char *line, size_t fst_len, t_game *game, int fd)
{
	size_t	len;

	len = ft_strlen(line);
	if (ft_strchr(line, '\n'))
		len -= 1;
	if (len != fst_len)
	{
		free(line);
		close(fd);
		ft_exit("Error\nInvalid map.\nMap not rectangle.", game, EXIT_FAILURE);
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
		ft_exit("Error\nCheck map!", game, EXIT_FAILURE);
	line_len = ft_strlen(line) - 1;
	game->map_y = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			ft_checkline_len(line, line_len, game, fd);
		game->map_y++;
	}
	if (line)
		free(line);
	close(fd);
	return (game->map_y);
}

void	ft_checkfile_end(t_game *game)
{
	char	*ending;
	int		i;

	ending = ft_strrchr(game->map_path, '.');
	if (!ending || ft_strlen(ending) != 4)
		ft_exit("Error\nInvalid map file.\n", game, EXIT_FAILURE);
	else
	{
		i = 0;
		while (ending[i] != '\0')
		{
			if (ending[i] != ".ber"[i])
				ft_exit("Error\nInvalid map file.\n", game, EXIT_FAILURE);
			i++;
		}
	}
}

void	ft_error_check(t_game *game, int ac, char **av)
{
	if (ac != 2)
		ft_exit("Error\nInvalid input.\n./so_long [maps]\n", game, EXIT_FAILURE);
	game->map_path = av[1];
	ft_checkfile_end(game);
	ft_numoflines(game);
}
