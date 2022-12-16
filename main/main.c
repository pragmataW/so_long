
#include "../libs/minilibx/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>



typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_vars
{
	void *mlx;
	void *win;
} t_vars;

void *mlx;
	void *mlx_win;
	t_data img;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int lol(int x, int y, void *param)
{
	
	printf("ananX:%d\nananY:%d\n", x, y);

	my_mlx_pixel_put((t_data *)param, x, y, 0xffffff);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);

	return 0;
}

int get_key(int keycode, t_vars *vars)
{
	printf("\n%d\n", keycode); // test keys

	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int main(void)
{
	


	
	int x = 0;
	int y = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	//DRAW IMAGE
	while (x < 500)
		my_mlx_pixel_put(&img, x++, y, 0xffffff);
	while (y < 500)
		my_mlx_pixel_put(&img, x, y++, 0xffffff);
	while (x > 0)
		my_mlx_pixel_put(&img, x--, y, 0xffffff);
	while (y > 0)
		my_mlx_pixel_put(&img, x, y--, 0xffffff);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);


	mlx_hook(mlx_win, 2, 1L << 0, get_key, &img);
	mlx_hook(mlx_win, 6, 1L << 6, lol, &img);

	mlx_loop(mlx);
}





/*
int main(void)
{
	t_vars vars;
	void *mlx;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	
	mlx_hook(vars.win, 2, 1L << 0, get_key, &vars);

	mlx_hook(vars.win, 6, 1L << 6, lol, &vars);
	mlx_loop(vars.mlx);
}
*/