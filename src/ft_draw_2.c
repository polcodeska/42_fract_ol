/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:41:33 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/06 16:51:53 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	ft_clear_canvas(t_fct *f)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
			ft_put_pxl_on_canvas(f->img, x, y++, 0x000000);
		x++;
	}
}

void	ft_set_colors(t_fct *f)
{
	f->g->color[0] = 0xFFFFFF;
	f->g->color[1] = 0xFC0019;
	f->g->color[2] = 0x01FF4F;
	f->g->color[3] = 0xFF01D7;
	f->g->color[4] = 0x5600CC;
	f->g->color[5] = 0x00EDF5;
	f->g->color[6] = 0xFFEB00;
	f->g->color[7] = 0xFF7500;
	f->g->color[8] = 0xFFEB00;
	f->g->color[9] = 0x379DB6;
	f->g->color[10] = 0x35CFDA;
	f->g->color[11] = 0xE60DAC;
	f->g->color[12] = 0xFF3A3A;
	f->g->color[13] = 0x49A423;
	f->g->color[14] = 0xEFE11F;
	f->g->color[15] = 0x6BF2AA;
	f->g->color[16] = 0x23FD0B;
	f->g->color[17] = 0x0B0BFD;
	f->g->color[18] = 0xB622AC;
	f->g->color[19] = 0x00FF44;
}

void	ft_coloring_the_canvas(t_fct *f)
{
	if (f->g->iter_count >= 30)
		ft_put_pxl_on_canvas(f->img, f->g->x_img, f->g->y_img, \
				f->g->color[0]);
	else
		ft_put_pxl_on_canvas(f->img, f->g->x_img, f->g->y_img, \
				f->g->color[f->g->iter_count % 20]);
}
