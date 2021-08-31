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
	var->tile.wall.ptr = mlx_xpm_file_to_image(var->mlx,
		"./assets_xpm/test_yellow32.xpm", &(var->tile.wall.width),
		&(var->tile.wall.height));
	var->tile.space.ptr = mlx_xpm_file_to_image(var->mlx,
		"./assets_xpm/test_green32.xpm", &(var->tile.space.width),
		&(var->tile.space.height));
	var->tile.exit.ptr = mlx_xpm_file_to_image(var->mlx,
		"./assets_xpm/test_stripe32.xpm", &(var->tile.exit.width),
		&(var->tile.exit.height));
}

void	init_player_img(t_var_set *var)
{
	var->player.image.ptr = mlx_xpm_file_to_image(var->mlx,
		"./assets_xpm/test_red32.xpm", &(var->player.image.width),
		&(var->player.image.height));
}

void	init_collec_img(t_var_set *var)
{
	var->collec.image.ptr = mlx_xpm_file_to_image(var->mlx,
		"./assets_xpm/test_collec.xpm", &(var->collec.image.width),
		&(var->collec.image.height));
}

void	init_game_img(t_var_set *var)
{
	init_tile_img(var);
	init_player_img(var);
	init_collec_img(var);
//	map_put_to_win(var);
// player_put_to_win(var);
// collec_put_to_win(var);
}
