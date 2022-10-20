/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:44:08 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/20 19:45:25 by tmasur           ###   ########.fr       */
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

int	ft_handle_mouse(int btn, int x, int y, t_fct *f)
{
	if (btn == 4)
	{
		f->g->range_real *= 0.8;
		f->g->range_im *= 0.8;
		ft_draw(f);
	}
	if (btn == 5)
	{
		f->g->range_real /= 0.8;
		f->g->range_im /= 0.8;
		ft_draw(f);
	}
	printf("x=%d, y=%d\n", x, y);
}

void	ft_change_detail_level(int key, t_fct *f)
{
	if (key == 45)
	{
		f->g->max_iter *= 0.9;
		ft_draw(f);
	}
	if (key == 43)
	{
		f->g->max_iter /= 0.9;
		ft_draw(f);
	}
}

void	ft_move_around(int key, t_fct *f)
{
	if (key == 119)
	{
		f->g->mid_im -= 0.1 * f->g->range_im;
		ft_draw(f);
	}
	if (key == 97)
	{
		f->g->mid_real -= 0.1 * f->g->range_real;
		ft_draw(f);
	}
	if (key == 115)
	{
		f->g->mid_im += 0.1 * f->g->range_im;
		ft_draw(f);
	}
	if (key == 100)
	{
		f->g->mid_real += 0.1 * f->g->range_real;
		ft_draw(f);
	}
}

int	ft_handle_keys(int key, t_fct *f)
{
	int	x;
	int	y;

	if (key == 65307)
		ft_exit(f);
	ft_change_detail_level(key, f);
	ft_move_around(key, f);
	return (0);
}
