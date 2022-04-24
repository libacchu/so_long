/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:24:13 by libacchu          #+#    #+#             */
/*   Updated: 2022/04/23 11:22:09 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_draw_rectangle(t_data img, int len, int wid, unsigned int color)
{
	int		i;
	int		j;
	int		grad_l;
	int		grad_w;
	t_trgb	scol;

	scol.t = get_t(color);
	scol.r = get_r(color);
	scol.b = get_b(color);
	scol.g = get_g(color);
	grad_l = ((int) len / 256) + 1;
	grad_w = ((int) wid / 256) + 1;
	i = 0;
	scol.tmp = scol.b;
	while (i < wid)
	{
		j = 0;
		scol.b = scol.tmp;
		while (j < len)
		{
			my_mlx_pixel_put(&img, j, i,
				create_trgb(scol.t, scol.r, scol.g, scol.b));
			if (j % grad_l == 0)
				scol.b += 1;
			j++;
		}
		if (i % grad_w == 0)
			scol.r += 1;
		i++;
	}
}
