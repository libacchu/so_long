/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:35:25 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/07 10:11:59 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_checkline_len(char *line, size_t fst_len)
{
	size_t	len;

	len = ft_strlen(line);
	if (ft_strchr(line, '\n'))
		len -= 1;
	if (len != fst_len)
	{
		ft_putstr_fd("Error:\nInvalid map size.\n", 1);
		exit (EXIT_FAILURE);
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

void	ft_checkfile_end(t_game *game)
{
	char	*ending;
	int		i;

	ending = ft_strrchr(game->map_path, '.');
	if (!ending || ft_strlen(ending) != 4)
	{	
		ft_putstr_fd("Error:\nInvalid map file.\n", 1);
		exit (EXIT_FAILURE);
	}
	else
	{
		i = 0;
		while (ending[i] != '\0')
		{
			if (ending[i] != ".ber"[i])
			{
				ft_putstr_fd("Error:\nInvalid map file.\n", 1);
				exit (EXIT_FAILURE);
			}
			i++;
		}
	}
}

void	ft_error_check(t_game *game, int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error:\nInvalid input.\n", 1);
		exit (EXIT_FAILURE);
	}
	game->map_path = av[1];
	ft_checkfile_end(game);
	ft_numoflines(game);
}
