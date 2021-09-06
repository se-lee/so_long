/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:40:31 by selee             #+#    #+#             */
/*   Updated: 2021/09/06 14:43:59 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_input(int keycode, t_var_set *var)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_to_directions(var, DIR_UP);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_to_directions(var, DIR_DOWN);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_to_directions(var, DIR_LEFT);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_to_directions(var, DIR_RIGHT);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
