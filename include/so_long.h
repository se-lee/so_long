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
# define BUFFER_SIZE 1

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

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
	int		row;
	int		column;

	// compositions (1, 0, P, E, C,)

}	t_map;

// tile struct
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

#endif



/* map functions */
// マップ読み込む
// マップのチェック
// マップのマロック
// マップ


