#include "../include/so_long.h"

void	free_map_arr(t_map *map)
{
	int	i;

	i = 0;
	while (map->array[i])
	{
		free(map->array[i]);
		i++;
	}
	free(map->array);
}
