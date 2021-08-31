#include "../include/so_long.h"

int		map_is_rectangular(t_var_set *var)
{
	int		width;
	int		height;
	
	width = var->map.column_count;
	height = var->map.row_count;

	if (width == height) //map is square
		return (0);
/*
how to check weird shaped maps?
column count is different in each line
*/
	return (1);
}

// check the first and last row
// for rows in between, check the first and last char
int		map_is_walled(t_var_set *var)
{
	int 	i;
	int		j;
	int		row;
	int		col;

	row = var->map.row_count;
	col = var->map.column_count;
	j = 0;
	while (j < var->map.column_count)
	{
		if (var->map.array[0][j] != '1'
			|| var->map.array[row - 1][j] != '1')
			return (0);
		j++;	
	}
	if (row > 2)
	{
		i = 1;
		while (var->map.array[i - 1])
		{
			j = 0;
			while (var->map.array[i][j])
			{
				if (var->map.array[i][0] != '1'
					|| var->map.array[i][col] != '1')
					return (0);
				j++;
			}
			i++;
		}
	}
	return (1);
}

int		map_has_correct_compo(t_var_set *var)
{
	int		i;
	int		j;

	i = 0;
	while (var->map.array[i])
	{
		j = 0;
		while (var->map.array[i][j])
		{
			if (var->map.array[i][j] != '0' || var->map.array[i][j] != '1'
				|| var->map.array[i][j] != 'P' || var->map.array[i][j] != 'E'
				|| var->map.array[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int		map_format_is_correct(t_var_set *var)
{
	if (!map_is_rectangular(var))
		return (0);
	if (!map_is_walled(var))
		return (0);
	if (!map_has_correct_compo(var))
		return (0);
	return (1);
}