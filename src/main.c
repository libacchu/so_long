/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:31:15 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/06 14:03:41 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main()
{
	t_window	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1920, 1080, "so_long");
	mlx_loop(win.mlx);
	return (0);
}
