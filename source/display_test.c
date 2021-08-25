#include "../include/so_long.h"
#include "../assets_xpm/test_green32.xpm"


void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

int	main()
{
	t_identifier id;
	t_image img;
	t_tile tile;
	int		i;
	int		j;
	int	color;
	char *relative_path = "./assets_xpm/test_green32.xpm";

	id.mlx = mlx_init();
	id.win = mlx_new_window(id.mlx, TILE_SIZE * 15, TILE_SIZE * 7, "test");
	img.img_ptr = mlx_xpm_file_to_image(id.mlx, relative_path, &tile.tile_width, &tile.tile_height);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	color = 0x70C9A1;

	i = 0;
	while (i < (TILE_SIZE * 7))
	{
printf("i: %d\n", i);
		j = 0;
		while (j < (TILE_SIZE * 15))
		{
			mlx_put_image_to_window(id.mlx, id.win, img.img_ptr, j, i);
			j = j + TILE_SIZE;
		}
		i = i + TILE_SIZE;
	}
	exit_game(&id);
	mlx_loop(id.mlx);
	return (0);
}
