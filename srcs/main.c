#include "../include/so_long.h"

/*
Your program must take as a first argument a map description file 
with the .ber extension.
*/
int	main(int argc, char **argv)
{
	char	*map_path;

	map_path = argv[1];
	if (argc == 2)
	{
		t_var_set	var;

		map_read_and_check(&var, map_path);
		init_game(&var);
	printf("mlx: %p, win: %p \n", var.mlx, var.win);
		init_game_img (&var);
	printf("start:{%d, %d}\n", var.player.x, var.player.y);	
		mlx_hook(var.win, EVENT_KEY_PRESS, 1L<<0, &key_direction, &var);
		mlx_loop_hook(var.mlx, &player_put_to_win, &var);
//		exit_game(&var);
		mlx_loop(var.mlx);
	}
}
//	mlx_hook(win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &param);
