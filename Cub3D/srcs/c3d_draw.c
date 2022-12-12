/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:03:54 by edlim             #+#    #+#             */
/*   Updated: 2022/12/07 17:43:32 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	c3d_my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->sl + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	c3d_draw_verline(t_img *img, int i, t_gm *gm)
{
	char	*dest;
	double	y;
	int		color;
	double	factor;

	y = 0;
	factor = ((double)(img->size.y - 1)
			/ (double)(gm->render.d_end - gm->render.d_start));
	while (gm->render.d_start < gm->render.d_end)
	{
		if (gm->render.d_start >= 0 && gm->render.d_start < WIN_H)
		{
			dest = img->addr + ((int)y * img->sl
					+ gm->render.tex_x * (img->bpp / 8));
			color = *(unsigned int *)dest;
			c3d_my_mlx_pixel_put(&gm->map.imgw, i, gm->render.d_start, color);
		}
		gm->render.d_start++;
		y = y + factor;
	}
}
