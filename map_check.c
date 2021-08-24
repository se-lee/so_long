#include "include/so_long.h"

int		map_is_rectangular(t_map *map) //+マップの二次元配列
{
	if (map->row_count != map->column_count)
		return (1);
	return (0);
}


int		map_is_walled(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	while (j < map->column_count)
	{
		if (map->map_arr[0][j] != 1)
			return (0);
	}

	while(map->map_arr[i])
	{

		i++;
	}
	return (1);
}


