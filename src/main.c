/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:40:04 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/20 19:41:28 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include <stdio.h>

void	ft_init(t_fct *f)
{
	f->g->range_real = 3.5;
	f->g->range_im = 2.0;
	f->g->mid_real = -0.75;
	f->g->mid_im = 0.0;
	f->g->max_iter = 50;
}

int	main(void)
{
	t_fct	*f;

	f = malloc(sizeof(*f));
	f->mlx = mlx_init();
	if (!f->mlx)
		return (1);
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract-ol");
	f->img = malloc(sizeof(*f->img));
	f->g = malloc(sizeof(*f->g));
	if (!f->win || !f->img || !f->g)
		return (1);
	f->img->instance = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	f->img->canvas = mlx_get_data_addr(f->img->instance,
			&f->img->bits_per_pixel, &f->img->line_len,
			&f->img->is_little_endian);
	ft_init(f);
	mlx_hook(f->win, 17, 0, ft_exit, f);
	mlx_hook(f->win, 2, 1L << 0, ft_handle_keys, f);
	mlx_mouse_hook(f->win, ft_handle_mouse, f);
	ft_draw(f);
	mlx_loop(f->mlx);
	return (0);
}
