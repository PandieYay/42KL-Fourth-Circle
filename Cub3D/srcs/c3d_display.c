/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:48:13 by schuah            #+#    #+#             */
/*   Updated: 2022/12/07 17:26:11 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	clearimgwindow(t_gm *gm)
{
	int	i;
	int	k;

	i = 0;
	while (i < WIN_W)
	{
		k = 0;
		while (k < WIN_H)
		{
			if (k < WIN_H / 2)
				c3d_my_mlx_pixel_put(&gm->map.imgw, i, k, gm->map.c_rgb.hex);
			else
				c3d_my_mlx_pixel_put(&gm->map.imgw, i, k, gm->map.f_rgb.hex);
			k++;
		}
		i++;
	}
}

int	c3d_display(t_gm *gm)
{
	clearimgwindow(gm);
	mlx_clear_window(gm->mlx, gm->win.ref);
	if (gm->win.mouse == 0)
		c3d_mouse_control(gm);
	c3d_render(gm);
	c3d_renderdoor(gm);
	c3d_display_minimap(gm);
	c3d_update_door(gm);
	return (0);
}
