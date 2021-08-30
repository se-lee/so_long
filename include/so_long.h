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
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_ARROW_UP 126
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124

# define X_EVENT_KEY_PRESS	2


/* assets / map files */

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

typedef struct s_map
{	
	char	**array;
	int		row_count;
	int		column_count;
}	t_map;

typedef struct s_map_compo
{
	int	wall;
	int	free_space;
	int	player_position;
	int	exit_position;
	int	collec_position;
}	s_map_compo;

typedef struct s_tile
{
	int		tile_width; // いらないかな
	int		tile_height; //いらないかな
	t_image	wall;
	t_image	exit;
	t_image	collect;
	t_image	space;
}		t_tile;

typedef struct s_move
{
	int	up_count;
	int	down_count;
	int	left_count;
	int	right_count;
}	t_move;

// coordinate struct
typedef struct s_coord
{
	int		x;
	int		y;
}	t_coord;

typedef struct s_player
{
	t_coord			coord;
	t_image			image;
	int				move_count;
}	t_player;

typedef struct s_collect
{
	t_coord coord;
	int		count;
//	t_image	c_image;??
}	t_collect;

typedef struct s_var_set
{
	void		*mlx;
	void		*win;
	t_player 	player;
	t_map		map;
	t_tile		tile;	
}	t_var_set;

/* initiate */
void	init_game(t_var_set *var);


#endif

/*
maybe make a struct the includes all structs above 
because passing too many variables are tiring
and i can only declare upto 5 variables in a function/

/* Map functions */
/*
int		get_next_line(int fd, char **line);
int		map_format_is_correct(t_map *map);
void	map_malloc(int fd, t_map *map);
void	map_read(char *map_filename, t_map *map);
void	map_draw_background(t_id *id, t_map *map, t_tile *tile);
void	map_draw_wall_and_background(t_id *id, t_map *map, t_tile *tile);
void 	map_get_player_coordinate(t_map *map, t_player *player);
int		move_player(t_id *id, t_player *player);
int		move_direction(t_player *player, int keycode);

int		exit_with_esc_key(int esc_keycode);
void	draw_32(t_id *id, t_image *img, int x, int y);
void	exit_game(t_id *id);
void	free_map_arr(t_map *map);
*/
