/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:44:08 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/06 12:44:10 by tmasur           ###   ########.fr       */
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

int	ft_handle_keys(int keyup, t_fct *f)
{
	if (keyup == 65307)
		ft_exit(f);
	return (0);
}
