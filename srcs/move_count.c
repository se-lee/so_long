#include "../include/so_long.h"


// count the number of movements and store the value into player struct, move_count
// count = when valid movement key was pressed --> handle this in movement functions

void	move_count_display(t_var_set *var)
{
	printf("movement count: %d\n", var->player.move_count);
}
