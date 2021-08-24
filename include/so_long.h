#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx_mms_20210621/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"

# define TILE_SIZE 32
# define BUFFER_SIZE 1  // いらないかも

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
	t_image	wall;
	t_image	exit;
	t_image	collect;
}		t_tile;

// coordinate struct
// player struct
// collectible struct




// 
// initiate images (xpm_to_img function)
// 
/* initiate struct values */


void	exit_game(t_identifier *id);

#endif



/* map functions */
// マップ読み込む
// マップのチェック
// マップのマロック
// マップ


