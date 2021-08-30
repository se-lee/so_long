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

int		map_is_walled(t_var_set *var)
{
/*
*/



}

int		map_has_correct_compo(t_var_set *var)
{
/*
*/
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