/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:23:32 by libacchu          #+#    #+#             */
/*   Updated: 2022/04/27 19:58:07 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_numoflines(t_image *game)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(game->map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line || !fd)
		return (0);
	i = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

void	ft_read_map(t_image *game)
{
	int	fd;
	int	i;

	game->map_y = ft_numoflines(game);
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

int main(void)
{
	t_image test = { 0 };

	test.map_path = "../maps/test.ber";
	ft_read_map(&test);
}
