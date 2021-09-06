/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:38:52 by selee             #+#    #+#             */
/*   Updated: 2021/09/06 17:12:26 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
when all collectibles are collected
(-> check map if there is no 'C')
and the player is at the exit,
display message (?) and quit
*/
void	error_message_exit(char *message)
{
	ft_putendl_fd(message, 2);
	exit(0);
}


int	player_collected_all(t_var_set *var)
{
	int		i;
	int		j;

	i = 0;
	while (i < var->map.row_count)
	{
		j = 0;
		while (j < var->map.column_count)
		{
			if (var->map.array[i][j] == 'C')
				return (0);
		}
	}
	return (1);
}

void	all_collected_exit_game(t_var_set *var)
{
	if (player_collected_all(var))// && player_touched_exit(var))
		ft_putendl_fd("collected all", 1);
	// return (0);
}
// void	check_game_status(t_var_set *var)
// {
// 	all_
// }
