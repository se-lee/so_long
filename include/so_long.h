/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:51:46 by selee             #+#    #+#             */
/*   Updated: 2021/09/06 19:04:21 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include "../minilibx_mms_20200219/mlx.h"
# include "../libft/libft.h"

# define TILE_SIZE 32
# define BUFFER_SIZE 1

/* keycode */
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

/* event */
# define EVENT_KEY_PRESS	2
# define EVENT_EXIT			17

/* direction */
# define DIR_UP 1
# define DIR_DOWN 2
# define DIR_LEFT 3
# define DIR_RIGHT 4

/* game status */
# define GAME_START	1
# define GAME_PLAY	2
# define GAME_END	3

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		height;
	int		width;
}	t_image;

typedef struct s_map
{	
	char	**array;
	int		row_count;
	int		column_count;
	int		p_count;
	int		c_count;
	int		e_count;
}	t_map;

typedef struct s_tile
{
	t_image	wall;
	t_image	exit;
	t_image	space;
}		t_tile;

typedef struct s_player
{
	int			x;
	int			y;
	int			move_count;
	t_image		image;
}	t_player;

typedef struct s_collec
{
	int			x;
	int			y;
	t_image		image;
}	t_collec;

typedef struct s_var_set
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_collec	collec;
	t_map		map;
	t_tile		tile;
}	t_var_set;

int		get_next_line(int fd, char **line);
void	init_game(t_var_set *var);
void	init_game_img(t_var_set *var);
void	init_mlx_and_win(t_var_set *var);
//int		map_format_is_correct(t_var_set *var);
void	map_check_format(t_var_set *var);
int		map_compo_is_correct(char c);
void	map_read_and_check(t_var_set *var, char *map_path);
void	map_put_to_win(t_var_set *var);
void	player_put_to_win(t_var_set *var);
int		key_input(int keycode, t_var_set *var);
void	map_get_player_coord(t_var_set *var);

void	move_up(t_var_set *var);
void	move_down(t_var_set *var);
void	move_left(t_var_set *var);
void	move_right(t_var_set *var);
void	move_to_directions(t_var_set *var, int direction);

int		player_touched_wall(t_var_set *var, int direction);
int		player_touched_collec(t_var_set *var);
void	collec_is_collected(t_var_set *var);
int		player_touched_exit(t_var_set *var);
int		collect_put_to_win(t_var_set *var);
void	map_count_compo(t_var_set *var, char c);
int		player_collected_all(t_var_set *var);
int		all_collected_exit_game(t_var_set *var);

void	exit_game(t_var_set *var);
int		exit_hook(void);
void	error_message_exit(char *message);

int		key_press(int keycode, t_var_set *var);

#endif
