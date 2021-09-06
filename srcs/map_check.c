/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:38:29 by selee             #+#    #+#             */
/*   Updated: 2021/09/06 16:57:37 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_is_rectangular(t_var_set *var)
{
	int		i;

	if (var->map.row_count == var->map.column_count)
		return (0);
	i = 0;
	while (i < var->map.row_count)
	{
		if (ft_strlen(var->map.array[i]) != var->map.column_count)
			return (0);
		i++;
	}
	return (1);
}
// error occurs when some lines are shorter than the max column count

int	map_is_walled(t_var_set *var)
{
	int		i;
	int		row;
	int		col;

	row = var->map.row_count;
	col = var->map.column_count;
	i = 0;
	while (i < col)
	{
		if (var->map.array[0][i] != '1' || var->map.array[row - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < row)
	{
		if (var->map.array[i][0] != '1' || var->map.array[i][col - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_has_correct_compo(t_var_set *var)
{
	int		i;
	int		j;

	i = 0;
	while (i < var->map.row_count)
	{
		j = 0;
		while (j < var->map.column_count)
		{
			if (!(var->map.array[i][j] == '0' || var->map.array[i][j] == '1'
				|| var->map.array[i][j] == 'P' || var->map.array[i][j] == 'E'
				|| var->map.array[i][j] == 'C'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	map_check_format(t_var_set *var)
{
	if (!map_is_rectangular(var))
		error_message_exit("Error: Map is not rectangular");
	if (!map_is_walled(var))
		error_message_exit("Error: Map is not walled");
	if (!map_has_correct_compo(var))
		error_message_exit("Error: Invalid composition");
	if (var->map.p_count > 1 || var->map.p_count < 1)
		error_message_exit("Error: Invalid number of players");
	if (var->map.c_count < 1)
		error_message_exit("Error: Invalid number of collectibles");
	if (var->map.e_count < 1)
		error_message_exit("Error: Invalid number of exit");
}
