/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:44:03 by schuah            #+#    #+#             */
/*   Updated: 2022/11/23 17:05:10 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

/* End == 0 : BGRA */
static void	change_color(t_gm *gm, unsigned int color, int pixel, char *addr)
{
	if (gm->map.main->end == 1)
	{
		addr[pixel + 0] = (color >> 24) & 0xFF;
		addr[pixel + 1] = (color >> 16) & 0xFF;
		addr[pixel + 2] = (color >> 8) & 0xFF;
		addr[pixel + 3] = (color) & 0xFF;
	}
	else if (gm->map.main->end == 0)
	{
		addr[pixel + 0] = (color) & 0xFF;
		addr[pixel + 1] = (color >> 8) & 0xFF;
		addr[pixel + 2] = (color >> 16) & 0xFF;
		addr[pixel + 3] = (color >> 24) & 0xFF;
	}
}

void	c3d_color_block(t_gm *gm, t_ivct cur, unsigned int color)
{
	t_dvct	px;

	px.y = -1;
	while (++px.y < MMAP_PX)
	{
		px.x = -1;
		while (++px.x < MMAP_PX)
		{
			change_color(gm, color,
				(((cur.y * MMAP_PX) + px.y) * gm->map.main->sl)
				+ (((cur.x * MMAP_PX) + px.x) * 4), gm->map.main->addr);
		}
	}
}

void	c3d_copy_main(t_gm *gm, int src_pixel, int x, int y)
{
	gm->map.mini->addr[(y * gm->map.mini->sl) + (x * 4) + 0]
		= gm->map.main->addr[src_pixel + 0];
	gm->map.mini->addr[(y * gm->map.mini->sl) + (x * 4) + 1]
		= gm->map.main->addr[src_pixel + 1];
	gm->map.mini->addr[(y * gm->map.mini->sl) + (x * 4) + 2]
		= gm->map.main->addr[src_pixel + 2];
	gm->map.mini->addr[(y * gm->map.mini->sl) + (x * 4) + 3]
		= gm->map.main->addr[src_pixel + 3];
}

void	c3d_color_image(t_gm *gm, t_img *img, int color)
{
	t_ivct	pos;

	pos.y = -1;
	while (++pos.y < MMAP_H * MMAP_PX)
	{
		pos.x = -1;
		while (++pos.x < MMAP_W * MMAP_PX)
			change_color(gm, color, (pos.y * img->sl) + (pos.x * 4), img->addr);
	}
}
