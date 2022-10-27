/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:41:33 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/20 19:20:25 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	ft_get_color(int iter_count)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)((iter_count * iter_count * 22) % 32 * 32);
	g = (unsigned char)(iter_count * iter_count * iter_count * 33) % 32 * 32;
	b = (unsigned char)iter_count * 77 % 32 * 32;
	return (r << 16 | g << 8 | b);
}

void	ft_coloring_px_on_canvas(t_fct *f, int iter_count, int x, int y)
{
	if (iter_count >= f->g->max_iter / 2)
		ft_put_pxl_on_canvas(f->img, x, y, \
				0x000000);
	else
		ft_put_pxl_on_canvas(f->img, x, y, \
				ft_get_color(iter_count));
}
