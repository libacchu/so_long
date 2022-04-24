/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:46:22 by libacchu          #+#    #+#             */
/*   Updated: 2022/04/24 18:53:57 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** MEMORY OFFSET FORMULA
** int offset = (y * line_length + x * (bits_per_pixel / 8));
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_window	win;
	t_image		main_c;

	main_c.img_height = 10;
	main_c.img_width = 10;
	main_c.x = 0;
	main_c.y = 0;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1920, 1080, "so_long");
	mlx_put_image_to_window(win.mlx, win.win, main_c.img, main_c.x, main_c.x);
	mlx_hook(win.win, 3, 1L << 0, ft_close, &win);
	mlx_key_hook(win.win, ft_move_img, &main_c);
	mlx_hook(win.win, 17, 0, ft_close_win, &win);
	main_c.img = mlx_xpm_file_to_image(win.mlx, IMAGE,
			&main_c.img_width, &main_c.img_height);
	mlx_loop(win.mlx);
}
