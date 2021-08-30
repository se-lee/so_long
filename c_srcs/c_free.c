#include "../include/so_long.h"

void	free_map_arr(t_map *map)
{
	int	i;

	i = 0;
	while (map->matrix[i])
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
}
