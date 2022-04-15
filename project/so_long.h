/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 07:29:20 by libacchu          #+#    #+#             */
/*   Updated: 2022/04/15 23:08:25 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <math.h>

// Window handling
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}		t_window;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// Drawing Image
void	ft_draw_rectangle(t_data img, int len, int wid, unsigned int color);
typedef struct s_square
{
	int				length;
	unsigned int	color;
}		t_square;

// Color handling
typedef struct s_trbg
{
	int	t;
	int	r;
	int	b;
	int	g;
	int	tmp;
}		t_trgb;
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

// Event handling
int		ft_close(int keystroke, t_window *win);
#endif
