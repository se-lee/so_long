/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:38:52 by selee             #+#    #+#             */
/*   Updated: 2021/09/08 11:47:04 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	exit_hook(t_var_set *var)
{
	free_map_arr(var);
	exit(0);
}

void	error_message_exit(char *message)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	exit(0);
}

void	player_at_exit(t_var_set *var)
{
	if (player_touched_exit(var))
	{
		if (collec_all_collected(var))
			var->status = GAME_END;
		else if (!(collec_all_collected(var)))
			var->status = GAME_CONTINUE;
	}
}
