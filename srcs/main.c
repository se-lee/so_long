/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:40:26 by selee             #+#    #+#             */
/*   Updated: 2021/09/06 17:10:57 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
Your program must take as a first argument a map description file 
with the .ber extension.
*/

int	exit_hook(void)
{
	exit(0);
}

int	game_loop(t_var_set *var)
{
	map_put_to_win(var);
	player_put_to_win(var);
	collec_is_collected(var);
	all_collected_exit_game(var);
	return (0);
}
/* 'all_collected_exit_game(var);' 
inside game_loop results in all white window...*/

int	main(int argc, char **argv)
{
	char		*map_path;
	t_var_set	var;

	map_path = argv[1];
	if (argc == 2)
	{
		map_read_and_check(&var, map_path);
		init_game(&var);
		init_game_img (&var);
		mlx_hook(var.win, EVENT_KEY_PRESS, 1L << 0, &key_input, &var);
		mlx_loop_hook(var.mlx, &game_loop, &var);
		mlx_hook(var.win, EVENT_EXIT, 0, exit_hook, 0);
		mlx_loop(var.mlx);
	}
	else if (argc < 2)
		error_message_exit("Error: Invalid argument");
}
