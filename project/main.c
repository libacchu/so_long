/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:46:22 by libacchu          #+#    #+#             */
/*   Updated: 2022/04/12 14:56:37 by libacchu         ###   ########.fr       */
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_close(int keystroke, t_window *win)
{
	(void) keystroke;
	mlx_destroy_window(win->mlx, win->win);
	exit (0);
}

int	main(void)
{
	t_window	win;
	t_data		img;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1920, 1080, "so_long");
	img.img = mlx_new_image(win.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	mlx_hook(win.win, 3, 1L << 0, ft_close, &win);
	ft_draw_square(img, 100, 0xFFFF00);
	mlx_put_image_to_window(win.mlx, win.win, img.img, 0, 0);
	mlx_loop(win.mlx);
}

	// while (i < 200)
	// {
	// 	j = 5;
	// 	while (j < 495)
	// 	{
	// 		my_mlx_pixel_put(&img, j, i, 0xFFFF00);
	// 		j++;
	// 	}
	// 	i++;
	// }