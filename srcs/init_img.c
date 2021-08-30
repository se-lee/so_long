#include "../include/so_long.h"

/* 
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
** Convert an xpm file to a new image instance.
**
** @param	void *mlx_ptr	the mlx instance;
** @param	char *filename	the file to load;
** @param	int  *width		a pointer to where the width ought to be written;
** @param	int  *height	a pointer to where the height ought to be written;
** @return	void*			the image instance.
*/

void	init_tile_img(t_var_set *var)
{
	var->tile.wall.ptr = mlx_xpm_file_to_image(var->mlx, "");
	var->tile.space.ptr = mlx_xpm_file_to_image(var->mlx, "");
	var->tile.exit.ptr = mlx_xpm_file_to_image(var->mlx, "");
}

void	init_player_img(t_var_set *var)
{
	var->player.image.ptr = mlx_xpm_file_to_image(var->mlx, "");
}





