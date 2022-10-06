/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:44:08 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/06 15:22:35 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	ft_exit(t_fct *f)
{
	mlx_destroy_image(f->mlx, f->img->instance);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	free(f->g);
	free(f->img);
	free(f);
	exit(0);
}

int	ft_handle_keys(int key, t_fct *f)
{
	if (key == 65307)
		ft_exit(f);
	if (key == 99)
	{
		ft_clear_canvas(f);
		mlx_mouse_get_pos(f->mlx, f->win, &f->g->x_img, &f->g->y_img);
		f->g->x_julia = f->g->min_x + (f->g->x_img * f->g->x_weight);
		f->g->y_julia = f->g->max_y - (f->g->y_img * f->g->y_weight);
		ft_draw_fract(f, ft_juliaset);
	}
	return (0);
}
