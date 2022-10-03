/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:08:02 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/02 11:23:48 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define WIN_HEIGHT 720
# define WIN_WIDTH 720

# include "../lib/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>

typedef struct	s_img_data {
	void	*id;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		is_little_endian;
}	t_img_data;

typedef struct	s_fct_data {
	void		*mlx;
	void		*win;
	t_img_data	img;
} t_fct_data;

void	ft_mlx_pixel_put(t_img_data *img, int x, int y, int color);
#endif

