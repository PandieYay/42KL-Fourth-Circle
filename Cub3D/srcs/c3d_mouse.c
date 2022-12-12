/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:29:08 by schuah            #+#    #+#             */
/*   Updated: 2022/11/24 12:51:08 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	c3d_mouse_control(t_gm *gm)
{
	t_ivct	ms;
	double	ratio;
	double	angle;

	mlx_mouse_get_pos(gm->win.ref, &ms.x, &ms.y);
	if (ms.x >= WIN_W)
		mlx_mouse_move(gm->win.ref, 0, WIN_H / 2);
	else if (ms.x <= 0)
		mlx_mouse_move(gm->win.ref, WIN_W, WIN_H / 2);
	else if (ms.y >= WIN_H || ms.y <= 0)
		mlx_mouse_move(gm->win.ref, ms.x, WIN_H / 2);
	ratio = ms.x / (double)WIN_W;
	angle = (M_PI * ratio * 2) - M_PI;
	gm->ply.dir.y = gm->ply.c_dir.x * cos(angle) + gm->ply.c_dir.y * sin(angle);
	gm->ply.dir.x = gm->ply.c_dir.y * cos(angle) - gm->ply.c_dir.x * sin(angle);
	gm->ply.plane.x = -gm->ply.dir.y;
	gm->ply.plane.y = gm->ply.dir.x;
}

void	c3d_mouse_state(t_gm *gm, int keycode)
{
	if (keycode == KEY_M)
	{
		if (gm->win.mouse == 0)
			mlx_mouse_show();
		else if (gm->win.mouse)
			mlx_mouse_hide();
		gm->win.mouse = gm->win.mouse == 0;
	}
}
