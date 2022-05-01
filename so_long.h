/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 07:29:20 by libacchu          #+#    #+#             */
/*   Updated: 2022/05/01 10:47:18 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

// Maps locations
# define MAP1

// Assets location
# define MAP_PLAYER "./assets/player.xpm"
# define MAP_EMPTY_SPACE "./assets/wooden.xpm"
# define MAP_WALLS "./assets/walls.xpm"
# define MAP_COLLECT "./assets/chest_01.xpm"
# define MAP_EXIT "./assets/exit.xpm"

// Window handling
typedef struct s_window
{
	void	*mlx;
	void	*win;
}		t_window;

// Keyboard
enum	e_keystroke
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
};

// Map characters
typedef struct s_mapc
{
	int	m_spaces;
	int	m_wall;
	int	m_collectible;
	int	m_exit;
	int	m_player;
}	t_mapc;

// Reading images
typedef struct s_game
{
	void	*img_player;
	void	*img_empty_space;
	void	*img_walls;
	void	*img_collect;
	void	*img_exit;
	char	**map;
	char	*map_path;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		map_x;
	int		map_y;
	int		x;
	int		y;
	t_mapc	*mapc;
}	t_game;

// Event handling
int		ft_close(int keystroke, t_window *win);
int		ft_close_win(int keycode, t_window *win);
int		key_hook(int keycode, t_window *win);
int		ft_move_img(int keystroke, t_game *img);

// Read Map
void	ft_read_map(t_game *game);
#endif
