#include "../include/so_long.h"

/*
when a key is pressed,
move
*/

int		move_up(t_map *map, t_player *player, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_ARROW_UP)
		player->coordi.y = player->coordi.y - 1;
	return (0);
}

int		move_down();

int		move_left();

int		move_right();

void	move_player(t_id *id)
{
	mlx_key_hook(id->win, move_up, &id); //?? 最後のパラメーターがよくわからない
}

