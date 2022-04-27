/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:23:32 by libacchu          #+#    #+#             */
/*   Updated: 2022/04/27 15:52:51 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_numoflines(void)
{
	char *line;
	int	fd;
	int	i;

	fd = open("../maps/test1.ber1", O_RDONLY);
	line = get_next_line(fd);
	if (!line || !fd)
		return (0);
	i = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

void	ft_read_map(t_image *game)
{
	int	fd;
	char buff[10000];
	int	i;
	int	x;

	game->map_y = ft_numoflines();
	fd = open("../maps/test1.ber1", O_RDONLY);
	ft_printf("\n y = %d\n", game->map_y);
	ft_printf("\n-------HERE-------\n");
	game->map = (char **)malloc(11 * sizeof(char *));
	i = 0;
	while (i < game->map_y)
	{
		game->map[i] = get_next_line(fd);
		ft_printf("%s", game->map[i]);
		i++;
	}
	game->map_x = ft_strlen(game->map[i]);
	ft_printf("\nx = %d\n", x);
}

int main(void)
{
	t_image test = { 0 };
	ft_read_map(&test);
}
