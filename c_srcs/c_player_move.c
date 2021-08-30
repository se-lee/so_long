#include "../include/so_long.h"

/*
when a key is pressed,
move
*/

int		move_direction(t_player *player, int keycode)
{
	static int a = 0;
	
	if (keycode == KEY_W || keycode == KEY_ARROW_UP)
		player->coord.y--;
	else if (keycode == KEY_S || keycode == KEY_ARROW_DOWN)
		player->coord.y++;
	else if (keycode == KEY_A || keycode == KEY_ARROW_LEFT)
		player->coord.x--;
	else if (keycode == KEY_D || keycode == KEY_ARROW_RIGHT)
		player->coord.x++;
	printf("player: x:%d  y: %d\n", player->coord.x, player->coord.y);
	return (0);
}

int		move_down();

int		move_left();

int		move_right();

int		move_player(t_id *id, t_player *player)
{
	mlx_hook(id->win, 2, 1L<<0, &move_direction, &player->coord); //?? 最後のパラメーターがよくわからない
	return (0);
}

