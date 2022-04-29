/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:10:57 by libacchu          #+#    #+#             */
/*   Updated: 2022/04/29 16:43:01 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	line_len = ft_strlen(line) - 1;
	if (!line || !fd)
		return (0);
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

void	ft_check_map_char(char *line, t_game *game)
{
	if (ft_strchr(line, '0'))
		game->
	
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == )
		i++;
	}
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
		ft_printf("%s", game->map[i]);
		i++;
	}
	game->map_x = ft_strlen(game->map[i - 1]);
	close(fd);
}
