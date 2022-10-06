/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:40:04 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/06 20:17:07 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include <stdio.h>

int	main(void)
{
	t_fct	*f;

	f = malloc(sizeof(*f));
	f->mlx = mlx_init();
	if (!f->mlx)
		return (1);
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract-ol");
	if (!f->win)
		return (1);
	f->img = malloc(sizeof(*f->img));
	f->img->instance = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	f->img->canvas = mlx_get_data_addr(f->img->instance,
			&f->img->bits_per_pixel, &f->img->line_len,
			&f->img->is_little_endian);
	f->g = malloc(sizeof(*f->g));
	if (!f->g)
		return (1);
	mlx_hook(f->win, 17, 0, ft_exit, f);
	mlx_hook(f->win, 2, 1L << 0, ft_handle_keys, f);
	//f->g->x_julia = 0.353;
	//f->g->y_julia = 0.288;
	//ft_draw_fract(f, ft_juliaset);
	ft_draw_fract(f, ft_mandelset);
	mlx_loop(f->mlx);
	return (0);
}
