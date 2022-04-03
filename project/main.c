/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:46:22 by libacchu          #+#    #+#             */
/*   Updated: 2022/04/03 20:41:42 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "so_long");
	img = mlx_new_image(mlx_ptr, 1920, 1080);
	mlx_loop(mlx_ptr);
}
