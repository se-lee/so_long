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

/* assets / map files */

typedef struct s_id
{
	void	*mlx;
	void	*win;
}	t_id;

typedef struct s_image
{
	void	*img_ptr;
	int		height;
	int		width;
	char	*addr;
	int		bits_per_pixel; 
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_map
{	
	char	**map_arr;
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
typedef struct s_coordinate
{
	int		x;
	int		y;
}	t_coordinate;

typedef struct s_player
{
	t_coordinate p_coordi;
	int		p_move_count;
//	t_image	p_image; ??
}	t_player;

typedef struct s_collect
{
	t_coordinate c_coordi;
	int		c_count;
//	t_image	c_image;??
}	t_collect;

// initiate images (xpm_to_img function)


/*
maybe make a struct the includes all structs above 
because passing too many variables are tiring
and i can only declare upto 5 variables in a function/


typedef struct s_gameset
{
	t_identifier 	id;
	t_tile			tile;
	t_map			map;
	t_collect		collect;
}	t_gameset;

*/ 


/* Map functions */
int		get_next_line(int fd, char **line);
int		map_format_is_correct(t_map *map);
void	map_malloc(int fd, t_map *map);
void	map_read(char *map_filename, t_map *map);
void	map_draw_background(t_id *id, t_map *map, t_tile *tile);
void	map_draw_wall_and_background(t_id *id, t_map *map, t_tile *tile);
int		exit_with_esc_key(int esc_keycode);
void	draw_32(t_id *id, t_image *img, int x, int y);
void	exit_game(t_id *id);
void	free_map_arr(t_map *map);
#endif
