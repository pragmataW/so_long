
#include "../libs/minilibx/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// int main(void)
// {
// 	void *mlx;
// 	void *mlx_win;
// 	t_data img;
// 	int x = 0;
// 	int y = 0;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	while (x < 500)
// 		my_mlx_pixel_put(&img, x++, y, 0xffffff);
// 	while (y < 500)
// 		my_mlx_pixel_put(&img, x, y++, 0xffffff);
// 	while (x > 0)
// 		my_mlx_pixel_put(&img, x--, y, 0xffffff);
// 	while (y > 0)
// 		my_mlx_pixel_put(&img, x, y--, 0xffffff);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 100,100);
// 	 mlx_loop(mlx);
// }

int	get_key(int keycode, t_vars *vars)
{
	printf("\n%d\n",keycode); //test keys
	printf("annen");
	if(keycode==53)
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int anan(int x, int y, void *param)
{
	(void)param;
	printf("ananX:%d\nananY:%d\n",x,y);
	return 0;
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, get_key, &vars);
		
mlx_hook(vars.win, 6, 1L<<6, anan, &vars);
	mlx_loop(vars.mlx);
}
