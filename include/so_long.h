/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 07:29:20 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/18 17:27:08 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

// Assets location
# define MAP_PLAYER "./assets/player.xpm"
# define MAP_EMPTY_SPACE "./assets/empty_space.xpm"
# define MAP_WALLS "./assets/wall.xpm"
# define MAP_COLLECT "./assets/collectible.xpm"
# define MAP_EXIT "./assets/exit.xpm"

// Keyboard
enum	e_keystroke
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
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
	int			map_x;
	int			map_y;
	int			x;
	int			y;
	int			points;
	int			amt_collectible;
	int			amt_of_moves;
	int			flag;
}		t_game;

// Event handling
int		ft_key(int keystroke, t_game *game);
int		ft_close_win(int keycode, t_game *game);
int		key_hook(int keycode, t_game *game);
int		ft_move_img(int keystroke, t_game *img);

// Read Map
void	ft_read_map(t_game *game);
void	ft_error_check(t_game *game, int ac, char **av);
int		ft_mouse(t_game *game);
void	print_map(t_game *game);

//image
void	ft_make_image(t_game *game);
void	put_to_screen(t_game *game);
void	make_player(t_game *game);
void	make_empty_space(t_game *game);
void	make_wall(t_game *game);
void	make_collectible(t_game *game);
void	make_exit(t_game *game);

// closing
void	ft_free_game(t_game *game);
void	ft_exit(char *str, t_game *game, int exit_number);

// Player moves
void	ft_move_right(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);

#endif
