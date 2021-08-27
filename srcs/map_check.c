#include "../include/so_long.h"

int		map_is_rectangular(t_map *map)
{
	int	i;

	i = 0;
	if (map->row_count == map->column_count)
		return (0);
	while (map->map_arr[i])
	{
		if (map->column_count != ft_strlen(map->map_arr[i]))
			return (0);
		i++;
	}
	return (1);
}

int		map_is_walled(t_map *map)
{
	int	i;
	int	j;
	
	j = 0;
	while (j < map->column_count)
	{
		if (map->map_arr[0][j] != '1' || map->map_arr[map->row_count - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	if (map->row_count > 3)
	{
		while(map->map_arr[i])
		{
			if (map->map_arr[i][0] != '1' || map->map_arr[i][map->column_count - 1] != '1')
				return (0);
			i++;
		}
	}
	return (1);
}

/* check if components are correct 1, 0, P, E, C */
// int		map_compo_is_correct(t_map *map)
// {
	
// }


int		map_format_is_correct(t_map *map)
{
	if (!map_is_rectangular(map))
	{
		ft_putendl_fd("Map is not rectangle", 1);
		return (0);
	}
	if (!map_is_walled(map))
	{
		ft_putendl_fd("Map is not walled", 1);
		return (0);
	}
	return (1);
}
