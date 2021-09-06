/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:38:52 by selee             #+#    #+#             */
/*   Updated: 2021/09/06 18:59:07 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		// i = 0;
		// while (i < var->map.row_count)
		// {
		// 	j = 0;
		// 	printf("arr[%d]:", i);
		// 	while (j < var->map.column_count)
		// 	{
		// 		printf("%c", var->map.array[i][j]);
		// 		j++;
		// 	}
		// 	printf("\n");
		// 	i++;
		// }

int	all_collected_exit_game(t_var_set *var)
{
	if (player_collected_all(var) && player_touched_exit(var))
	{
		ft_putendl_fd("collected all", 1);
	}
	return (0);
}
