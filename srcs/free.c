#include "../include/so_long.h"

void	free_map_arr(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_arr[i])
	{
		free(map->map_arr[i]);
		i++;
	}
}
