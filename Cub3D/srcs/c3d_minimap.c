/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:42:06 by schuah            #+#    #+#             */
/*   Updated: 2022/11/23 17:51:33 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	create_new_image(t_gm *gm, int type)
{
	if (type == 1 && gm->map.main->ref == NULL)
	{
		gm->map.main->ref = mlx_new_image(gm->mlx, gm->map.size.x * MMAP_PX,
				gm->map.size.y * MMAP_PX);
		gm->map.main->addr = mlx_get_data_addr(gm->map.main->ref,
				&gm->map.main->bpp, &gm->map.main->sl, &gm->map.main->end);
	}
	else if (type == 2)
	{
		if (gm->map.mini->ref != NULL)
			mlx_destroy_image(gm->mlx, gm->map.mini->ref);
		gm->map.mini->ref = mlx_new_image(gm->mlx,
				MMAP_W * MMAP_PX, MMAP_H * MMAP_PX);
		gm->map.mini->addr = mlx_get_data_addr(gm->map.mini->ref,
				&gm->map.mini->bpp, &gm->map.mini->sl, &gm->map.mini->end);
	}
}

static void	create_map(t_gm *gm)
{
	t_ivct	cur;

	if (gm->map.main->ref == NULL)
	{
		create_new_image(gm, 1);
		cur.y = -1;
		while (++cur.y < gm->map.size.y)
		{
			cur.x = -1;
			while (++cur.x < gm->map.size.x)
			{
				if (gm->map.map[cur.y][cur.x] == '1')
					c3d_color_block(gm, cur, TWHITE);
				else if (gm->map.map[cur.y][cur.x] == 'D')
					c3d_color_block(gm, cur, TBROWN);
				else if (gm->map.map[cur.y][cur.x] == ' ')
					c3d_color_block(gm, cur, TRANS);
				else
					c3d_color_block(gm, cur, TGREY);
			}
		}
	}
}

static void	create_minimap(t_gm *gm)
{
	t_ivct	cur;
	t_ivct	max;
	t_ivct	min;

	create_new_image(gm, 2);
	c3d_color_image(gm, gm->map.mini, TRANS);
	min.y = (gm->ply.pos.y * MMAP_PX) - (MMAP_PX * (MMAP_H / 2)) - 1;
	max.y = (gm->ply.pos.y * MMAP_PX) + (MMAP_PX * ((MMAP_H / 2) + 1));
	min.x = (gm->ply.pos.x * MMAP_PX) - (MMAP_PX * (MMAP_W / 2)) - 1;
	max.x = (gm->ply.pos.x * MMAP_PX) + (MMAP_PX * ((MMAP_W / 2) + 1));
	cur.y = min.y;
	while (++cur.y < max.y)
	{
		cur.x = min.x;
		while (++cur.x < max.x)
		{
			if (cur.x >= 0 && cur.y >= 0
				&& cur.x <= (gm->map.size.x * MMAP_PX) - 1
				&& cur.y <= (gm->map.size.y * MMAP_PX) - 1)
				c3d_copy_main(gm, (cur.y * gm->map.main->sl) + (cur.x * 4),
					cur.x - min.x - 1, cur.y - min.y - 1);
		}
	}
}

static void	draw_player(t_gm *gm)
{
	t_ivct	pos;

	pos.x = MMAP_W * MMAP_PX / 2;
	pos.y = MMAP_H * MMAP_PX / 2;
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x - 1, pos.y - 1, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x, pos.y - 1, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x + 1, pos.y - 1, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x - 1, pos.y, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x, pos.y, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x + 1, pos.y, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x - 1, pos.y + 1, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x, pos.y + 1, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x + 1, pos.y + 1, GREEN);
}

void	c3d_display_minimap(t_gm *gm)
{
	create_map(gm);
	create_minimap(gm);
	draw_player(gm);
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.mini->ref, 0, 0);
}
