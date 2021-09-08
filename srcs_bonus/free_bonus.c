/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 18:19:02 by selee             #+#    #+#             */
/*   Updated: 2021/09/08 11:47:06 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	free_map_arr(t_var_set *var)
{
	int	i;

	i = 0;
	while (i < var->map.row_count)
	{
		free(var->map.array[i]);
		i++;
	}
	free(var->map.array);
}
