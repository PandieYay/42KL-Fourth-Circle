/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:23:52 by edlim             #+#    #+#             */
/*   Updated: 2022/12/07 17:44:00 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	check_hit(t_gm *gm)
{
	while (gm->render.hit == 0)
	{
		if (gm->render.side_dist.x < gm->render.side_dist.y)
		{
			gm->render.side_dist.x += gm->render.delta_dist.x;
			gm->render.map.x += gm->render.step.x;
			gm->render.side = 0;
		}
		else
		{
			gm->render.side_dist.y += gm->render.delta_dist.y;
			gm->render.map.y += gm->render.step.y;
			gm->render.side = 1;
		}
		if (gm->map.map[(int)gm->render.map.y][(int)gm->render.map.x] == '1')
			gm->render.hit = 1;
	}
	if (gm->render.side == 0)
		gm->render.perp_wall_dist = (gm->render.side_dist.x
				- gm->render.delta_dist.x);
	else
		gm->render.perp_wall_dist = (gm->render.side_dist.y
				- gm->render.delta_dist.y);
}

static t_img	*set_image(t_gm *gm)
{
	t_img	*curimg;

	if (gm->render.side == 0)
	{
		if (gm->render.step.x == 1)
			curimg = &gm->map.e_img;
		else
			curimg = &gm->map.w_img;
	}
	else
	{
		if (gm->render.step.y == 1)
			curimg = &gm->map.s_img;
		else
			curimg = &gm->map.n_img;
	}
	return (curimg);
}

void	c3d_render(t_gm *gm)
{
	t_img	*curimg;
	int		x;

	x = -1;
	while (++x < WIN_W)
	{
		c3d_set_variables(gm, x);
		c3d_check_steps(gm);
		check_hit(gm);
		curimg = set_image(gm);
		c3d_set_length(gm);
		c3d_check_sides(gm, curimg);
		c3d_draw_verline(curimg, x, gm);
	}
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.imgw.ref, 0, 0);
}
