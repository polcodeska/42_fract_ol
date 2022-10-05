#include "../include/fract_ol.h"

int	ft_exit(t_fct *fct)
{
	mlx_destroy_image(fct->mlx, fct->img->addr);
	mlx_destroy_window(fct->mlx, fct->win);
	free(fct->img);
	exit(0);
}

int	ft_handle_keys(int key_pressed, t_fct *fct)
{
	printf("Key: %d was pressed!\n", key_pressed);
	if (key_pressed == 65307)
		ft_exit(fct);
	return (0);
}
