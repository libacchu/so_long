/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 07:29:20 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/13 13:38:48 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_opengl/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

// Maps locations
# define MAP1

// Assets location
# define MAP_PLAYER "./assets/player.xpm"
# define MAP_EMPTY_SPACE "./assets/empty_space.xpm"
# define MAP_WALLS "./assets/wall.xpm"
# define MAP_COLLECT "./assets/collectible.xpm"
# define MAP_EXIT "./assets/exit.xpm"

// Window handling
typedef struct s_window
{
	void	*mlx;
	void	*win;
}		t_window;

typedef struct s_image
{
    void	*img;
    char	*addr;
    char	*path;
    int		bpp;
    int		line_len;
    int		endian;
}	t_image; 

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
	int	m_newline;
}	t_mapc;

// Reading images
typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img_player;
	void		*img_empty_space;
	void		*img_wall;
	void		*img_collectible;
	void		*img_exit;
	char		**map;
	char		*map_path;
	int			player_x;
	int			player_y;
	char		*relative_path;
	int			img_width;
	int			img_height;
	int			map_x;
	int			map_y;
	int			x;
	int			y;
	int			points;
	int			amt_collectible;
	int			flag;
	t_mapc		*mapc;
}		t_game;

// Event handling
int		ft_key(int keystroke, t_game *game);
int		ft_close_win(int keycode, t_window *win);
int		key_hook(int keycode, t_window *win);
int		ft_move_img(int keystroke, t_game *img);

// Read Map
void	ft_read_map(t_game *game);
void	ft_error_check(t_game *game, int ac, char **av);
int		ft_mouse(t_window *vars);

//image
void	ft_make_image(t_game *game);
void	put_to_screen(t_game *game);

// closing
void	ft_free_game(t_game *game);
void	ft_exit(char *str, t_game *game, int exit_number);
#endif
