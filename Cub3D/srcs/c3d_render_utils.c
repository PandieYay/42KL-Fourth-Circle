/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:31:10 by edlim             #+#    #+#             */
/*   Updated: 2022/12/07 17:44:00 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	c3d_set_variables(t_gm *gm, int x)
{
	gm->render.camera_x = 2 * x / (double)WIN_W - 1;
	gm->render.raydir.x = gm->ply.dir.x + gm->ply.plane.x
		* gm->render.camera_x;
	gm->render.raydir.y = gm->ply.dir.y + gm->ply.plane.y
		* gm->render.camera_x;
	gm->render.offset.x = gm->ply.pos.x + 0.5;
	gm->render.offset.y = gm->ply.pos.y + 0.5;
	gm->render.map.x = (int)gm->render.offset.x;
	gm->render.map.y = (int)gm->render.offset.y;
	if (gm->render.raydir.x == 0)
		gm->render.delta_dist.x = 1e30;
	else
		gm->render.delta_dist.x = fabs(1 / gm->render.raydir.x);
	if (gm->render.raydir.y == 0)
		gm->render.delta_dist.y = 1e30;
	else
		gm->render.delta_dist.y = fabs(1 / gm->render.raydir.y);
	gm->render.hit = 0;
}

void	c3d_check_steps(t_gm *gm)
{
	if (gm->render.raydir.x < 0)
	{
		gm->render.step.x = -1;
		gm->render.side_dist.x = (gm->render.offset.x - gm->render.map.x)
			* gm->render.delta_dist.x;
	}
	else
	{
		gm->render.step.x = 1;
		gm->render.side_dist.x = (gm->render.map.x + 1.0 - gm->render.offset.x)
			* gm->render.delta_dist.x;
	}
	if (gm->render.raydir.y < 0)
	{
		gm->render.step.y = -1;
		gm->render.side_dist.y = (gm->render.offset.y - gm->render.map.y)
			* gm->render.delta_dist.y;
	}
	else
	{
		gm->render.step.y = 1;
		gm->render.side_dist.y = (gm->render.map.y + 1.0 - gm->render.offset.y)
			* gm->render.delta_dist.y;
	}
}

void	c3d_set_length(t_gm *gm)
{
	gm->render.line_h = (int)(WIN_H / gm->render.perp_wall_dist);
	gm->render.d_start = -gm->render.line_h / 2 + WIN_H / 2;
	gm->render.d_end = gm->render.line_h / 2 + WIN_H / 2;
	if (gm->render.side == 0)
		gm->render.wall_x = gm->render.offset.y
			+ gm->render.perp_wall_dist * gm->render.raydir.y;
	else
		gm->render.wall_x = gm->render.offset.x
			+ gm->render.perp_wall_dist * gm->render.raydir.x;
	gm->render.wall_x -= floor((gm->render.wall_x));
}

void	c3d_check_sides(t_gm *gm, t_img *curimg)
{
	gm->render.tex_x = (int)(gm->render.wall_x * (double)(curimg->size.x));
	if (gm->render.side == 0)
	{
		if (gm->render.raydir.x > 0)
			gm->render.tex_x = curimg->size.x
				- (curimg->size.x - gm->render.tex_x - 1);
		else
			gm->render.tex_x = curimg->size.x
				- gm->render.tex_x - 1;
	}
	if (gm->render.side == 1)
	{
		if (gm->render.raydir.y < 0)
			gm->render.tex_x = curimg->size.x
				- (curimg->size.x - gm->render.tex_x - 1);
		else
			gm->render.tex_x = curimg->size.x
				- gm->render.tex_x - 1;
	}
}
