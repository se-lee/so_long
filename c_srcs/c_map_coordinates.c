#include "../include/so_long.h"

/* get information from map file and store coodinates of each component */

/* 
二次元配列のマップ（テキスト）ファイルを読み込んで、
タイルの大きさをかけてウィンドウを生成する。

x軸の座標　i x size of tile（Width of a tile)
y軸の座量　j x size of tile（Height of a tile)

イメージを書き始めるピクセルの座標を指定して、
↓↓
CorrespondするCharが何か判断して
↓↓
それに沿って指定のタイルファイル（XPM）をのせる

*/

void 	map_get_player_coordinate(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row_count)
	{
		j = 0;
		while (j < map->column_count)
		{
			if (map->array[i][j] == 'P')
			{
				player->coord.x = j;
				player->coord.y = i;
			}
			j++;
		}
		i++;
	}
}

void	map_get_collec_coordinate(t_map *map, t_collect *collect)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->row_count)
	{
		j = 0;
		while (j < map->column_count)
		{
			if (map->array[i][j] == 'C')
			{
				collect->c_coordi.x = j;
				collect->c_coordi.y = i;
			}
			j++;
		}
		i++;
	}
}


/* set exit coordinate */




