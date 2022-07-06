/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:35:25 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/06 14:42:59 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_checkfile_end(t_game *game, int ac, char **av)
{
	char	*ending;
	int		i;

	if (ac != 2)
	{
		ft_putstr_fd("Error:\nInvalid input.\n", 1);
		// perror("Invalid input.");
		return (1);
	}
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
