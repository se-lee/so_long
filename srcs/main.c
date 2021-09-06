#include "../include/so_long.h"

/*
Your program must take as a first argument a map description file 
with the .ber extension.
*/

int		exit_hook()
{
	exit(0);
}

int	game_loop(t_var_set *var)
{
	map_put_to_win(var);
	player_put_to_win(var);
//	collect_put_to_win(var);
	collec_is_collected(var);
	// all_collected_exit_game(var); // ??
	return (0);
}

int	main(int argc, char **argv)
{
	char	*map_path;

	map_path = argv[1];
	if (argc == 2)
	{
		t_var_set	var;

		map_read_and_check(&var, map_path);
		init_mlx_and_win(&var);
		init_game_img (&var);
printf("start:{%d, %d}\n", var.player.x, var.player.y);
		mlx_hook(var.win, EVENT_KEY_PRESS, 1L<<0, &key_direction, &var);
		mlx_loop_hook(var.mlx, &game_loop, &var);
		mlx_hook(var.win, EVENT_KEY_EXIT, 0, exit_hook, 0);
		mlx_loop(var.mlx);
	}
}
