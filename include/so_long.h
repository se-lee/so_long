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

# define EVENT_KEY_PRESS	2
# define EVENT_KEY_EXIT		17

/* not working. why what did i do wrong */
#if DEBUG
#define debug(f, ...) f(__VA_ARGS__)
#else
#define debug(f, ...)
#endif
//debug(printf(""));

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel; 
	int		size_line;
	int		endian;
}	t_image;
// erase bpp, size_line, endian??

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

/*
Linked list for collec ?
*/

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
	t_player 	player;
	t_collec	collec;
	t_map		map;
	t_tile		tile;
}	t_var_set;

int		get_next_line(int fd, char **line);
void	init_game(t_var_set *var);
void	init_game_img(t_var_set *var);
void	init_mlx_and_win(t_var_set *var);
int		map_format_is_correct(t_var_set *var);
void	map_read_and_check(t_var_set *var, char *map_path);
void	map_put_to_win(t_var_set *var);
int		player_put_to_win(t_var_set *var);
int		key_direction(int keycode, t_var_set *var);
void	map_get_player_coord(t_var_set *var);


/* movement */
void	move_up(t_var_set *var);
void	move_down(t_var_set *var);
void	move_left(t_var_set *var);
void	move_right(t_var_set *var);

void	exit_game(t_var_set *var);
int		exit_hook();


/* test funct */
int		key_press(int keycode, t_var_set *var);

#endif












/*
int		map_format_is_correct(t_map *map);
void	map_malloc(int fd, t_map *map);
void	map_read(char *map_filename, t_map *map);
void	map_draw_background(t_id *id, t_map *map, t_tile *tile);
void	map_draw_wall_and_background(t_id *id, t_map *map, t_tile *tile);
void 	map_get_player_coordinate(t_map *map, t_player *player);
int		move_player(t_id *id, t_player *player);
int		move_direction(t_player *player, int keycode);

int		exit_with_esc_key(int esc_keycode);
void	exit_game(t_id *id);
void	free_map_arr(t_map *map);
*/
