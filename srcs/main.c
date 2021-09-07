/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:40:26 by selee             #+#    #+#             */
/*   Updated: 2021/09/07 19:33:30 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	game_loop(t_var_set *var)
{
	if (var->status == GAME_START)
		put_start_messsage(var);
	if (var->status == GAME_PLAY)
	{
		put_map_to_win(var);
		put_player_to_win(var);
		collec_is_collected(var);
		player_at_exit(var);
		put_step_count_to_win(var);
	}
	else if (var->status == GAME_CONTINUE)
		put_continue_messsage(var);
	else if (var->status == GAME_END)
		put_end_messsage(var);
	return (0);
}

int	main(int argc, char **argv)
{
	char		*map_path;
	t_var_set	var;

	if (argc != 2)
		error_message_exit("Invalid argument");
	map_path = argv[1];
	var.status = GAME_START;
	map_check_file_extension(map_path, ".ber");
	map_read_and_check(&var, map_path);
	init_game(&var);
	init_game_img (&var);
	mlx_hook(var.win, EVENT_KEY_PRESS, 1L << 0, &key_input, &var);
	mlx_loop_hook(var.mlx, &game_loop, &var);
	mlx_hook(var.win, EVENT_EXIT, 0, exit_hook, 0);
	mlx_loop(var.mlx);
}
