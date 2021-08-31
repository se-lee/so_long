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

/* TO BE ERASED LATER -- not working. why*/
#if DEBUG
#define debug(f, ...) f(__VA_ARGS__)
#else
#define debug(f, ...)
#endif
//debug(printf(""));

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
// erase bpp, size_line, endian

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

/* linked list for collec */
typedef struct s_clist
{
	struct s_clist *next;
}	t_clist;


// typedef struct s_c_node
// {
// 	int				content;
// 	struct s_node	*next;
// }				t_node;

typedef struct s_spr
{
	t_image	imgx[5][3];
	int		frame;
	int		frame_max;
	int		step;
	int		x;
	int		y;
	int		x0;
	int		y0;
	int		i;
	int		dir;
	int		move;
}	t_spr;

typedef struct s_player
{
	t_coord		coord;
	int			x;
	int			y;
	t_image		image;
	t_spr		spr; //???
	int			move_count;
}	t_player;

typedef struct s_collec
{
	t_image		image;
	int			x;
	int			y;
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

/* initiate */
int		get_next_line(int fd, char **line);
void	init_game(t_var_set *var);
void	init_game_img(t_var_set *var);
int		map_format_is_correct(t_var_set *var);
void	map_read_and_check(t_var_set *var, char *map_path);
void	map_put_to_win(t_var_set *var);
int		player_put_to_win(t_var_set *var);
int		key_event(t_var_set *var, int keycode);
void	map_get_player_coord(t_var_set *var);

/* movement */
void	move_up(t_var_set *var);
void	move_down(t_var_set *var);
void	move_left(t_var_set *var);
void	move_right(t_var_set *var);

void	exit_game(t_var_set *var);

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
void	draw_32(t_id *id, t_image *img, int x, int y);
void	exit_game(t_id *id);
void	free_map_arr(t_map *map);
*/
