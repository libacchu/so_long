/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 07:29:20 by libacchu          #+#    #+#             */
/*   Updated: 2022/04/24 18:39:50 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <math.h>

# define IMAGE "./assets/baum1.xpm"
# define PLAYER "./assets/player.xpm"

// Window handling
typedef struct s_window
{
	void	*mlx;
	void	*win;
}		t_window;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

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

// Keyboard
enum	e_keystroke
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
};

// Reading images
typedef struct s_image
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
}	t_image;

// Event handling
int		ft_close(int keystroke, t_window *win);
int		ft_close_win(int keycode, t_window *win);
int		key_hook(int keycode, t_window *win);
int		ft_move_img(int keystroke, t_image *img);

#endif
