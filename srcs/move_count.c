/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:51:18 by selee             #+#    #+#             */
/*   Updated: 2021/09/06 14:51:19 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// count the number of movements and store the value into player struct, move_count
// count = when valid movement key was pressed --> handle this in movement functions

void	move_count_display(t_var_set *var)
{
	printf("movement count: %d\n", var->player.move_count);
}
