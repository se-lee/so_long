/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:38:52 by selee             #+#    #+#             */
/*   Updated: 2021/09/08 12:54:17 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_hook(void)
{
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
