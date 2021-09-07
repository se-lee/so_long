/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:51:46 by selee             #+#    #+#             */
/*   Updated: 2021/09/07 18:23:49 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define TILE_SIZE		32
# define BUFFER_SIZE	1

/* keycode */
# define KEY_ESC 	53
# define KEY_SPACE	49
# define KEY_W 		13
# define KEY_A		 0
# define KEY_S		 1
# define KEY_D		 2
# define KEY_UP 	126
# define KEY_DOWN 	125
# define KEY_LEFT 	123
# define KEY_RIGHT 	124

/* event */
# define EVENT_KEY_PRESS	2
# define EVENT_EXIT			17

/* direction */
# define DIR_UP		1
# define DIR_DOWN	2
# define DIR_LEFT	3
# define DIR_RIGHT	4

/* game status */
# define GAME_START		1
# define GAME_PLAY		2
# define GAME_CONTINUE	3
# define GAME_END		4

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
	int			x_start;
	int			y_start;
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
	int			status;
}	t_var_set;

/* init */
void	init_game(t_var_set *var);
void	init_game_img(t_var_set *var);
void	init_mlx_and_win(t_var_set *var);
void	init_map_value(t_var_set *var);

/* utils */
int		get_next_line(int fd, char **line);
void	free_map_arr(t_var_set *var);

/* map */
int		map_compo_is_correct(char c);
int		map_check_file_extension(char *filename, char *ext);
void	map_check_format(t_var_set *var);
void	map_read_and_check(t_var_set *var, char *map_path);
void	map_count_compo(t_var_set *var, char c);

/* move */
void	move_up(t_var_set *var);
void	move_down(t_var_set *var);
void	move_left(t_var_set *var);
void	move_right(t_var_set *var);
void	move_to_directions(t_var_set *var, int direction);

/* player */
int		player_touched_wall(t_var_set *var, int direction);
int		player_touched_collec(t_var_set *var);
int		player_touched_exit(t_var_set *var);
void	player_get_coord(t_var_set *var);
void	player_resume_position(t_var_set *var);
void	player_at_exit(t_var_set *var);

/* collec */
void	collec_is_collected(t_var_set *var);
int		collec_all_collected(t_var_set *var);

/* key events */
int		key_input(int keycode, t_var_set *var);

/* display */
void	put_map_to_win(t_var_set *var);
void	put_player_to_win(t_var_set *var);
void	put_start_messsage(t_var_set *var);
void	put_continue_messsage(t_var_set *var);
void	put_end_messsage(t_var_set *var);

/* exit */
void	exit_game(t_var_set *var);
int		exit_hook(void);
void	error_message_exit(char *message);

#endif
