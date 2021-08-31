#include "../include/so_long.h"

int	main()
{
	t_var_set	var;

	map_read_and_check(&var);
	init_game(&var);
printf("mlx: %p, win: %p \n", var.mlx, var.win);
	init_game_img (&var);
	player_put_to_win(&var);
	mlx_loop(var.mlx);
}
