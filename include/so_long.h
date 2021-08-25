#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include "../minilibx_mms_20210621/mlx.h"
# include "../libft/libft.h"

# define TILE_SIZE 32
# define BUFFER_SIZE 1  // いらないかも

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


typedef struct s_identifier
{
	void	*mlx;
	void	*win;
}	t_identifier;

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
	int		tile_width;
	int		tile_height;
	t_image	wall;
	t_image	exit;
	t_image	collect;
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

*/ 


/* Map functions */
int		get_next_line(int fd, char **line);
int		map_format_is_correct(t_map *map);
void	map_malloc(int fd, t_map *map);
void	map_read(char *map_filename, t_map *map);
void	map_draw_background(t_identifier *id, t_image *img, t_map *map, t_tile *tile);

void	exit_game(t_identifier *id);

#endif
