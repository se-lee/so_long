#include "../include/so_long.h"

/* when player coord meets the coords of '1's, 
 the player can no longer move.
 check whether the coord of player corresponds to walls
 and do next actions
 if wall is met (turn "touched" to 1)

map.array[i][j] == '1' のとき
進もうとしている方向に壁があるか確認する

例えば、
右に行こうとした場合、今のプレーヤー座標からXを＋１した位置に
対応する文字が'1'と合致するかどうか。

左に向かう場合は 現在位置ｘより−１、
上は現在位置ｙより−１、
下は現在位置ｙより＋１ を確認する

座標をセットで比べる必要がある・・・
例えば
map.array[i][j] とあれば
	i は y
	j は x に対応する

よって、
プレーヤーの座標が ｛x, y｝だから
右に行くときは map.arry[i][j + 1]
左は map.arry[i][j - 1]
上は map.arry[i - 1][j]
下は map.arry[i + 1][j] に対応する文字が１かどうか確認する

*/

/*
int		player_touched_wall(t_var_set *var)
{
	int		i;
	int		j;

	i = var->player.y;
	j = var->player.x;
	if (var->map.array[i][j] == '1')
		return (1);
	return (0);
}
*/

int		player_touched_wall(t_var_set *var, int direction)
{
	int		i;
	int		j;
	
	i = var->player.y;
	j = var->player.x;
	return ((direction == DIR_UP && var->map.array[i - 1][j] == '1')
		|| (direction == DIR_DOWN && var->map.array[i + 1][j] == '1')
		|| (direction == DIR_LEFT && var->map.array[i][j - 1] == '1')
		|| (direction == DIR_RIGHT && var->map.array[i][j + 1] == '1'));
}

int		player_touched_collec(t_var_set *var);



/*
 Eの位置とかぶったら試合終了
*/
