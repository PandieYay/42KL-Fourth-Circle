/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:36:13 by schuah            #+#    #+#             */
/*   Updated: 2022/12/07 17:36:32 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static int	check_square(t_gm *gm, int x, int y)
{
	if (y < 0 || y >= gm->map.size.y || x < 0 || x >= gm->map.size.x)
		return (1);
	return (gm->map.map[y][x] != '1' && gm->map.map[y][x] != '0'
		&& gm->map.map[y][x] != 'N' && gm->map.map[y][x] != 'E'
		&& gm->map.map[y][x] != 'S' && gm->map.map[y][x] != 'W'
		&& gm->map.map[y][x] != 'D');
}	

static void	set_dir(t_gm *gm, int dir, int x, int y)
{
	gm->ply.e_dir = dir;
	gm->ply.c_dir.x = x;
	gm->ply.c_dir.y = y;
	gm->ply.dir.x = x;
	gm->ply.dir.y = y;
	if (dir == NORTH)
		gm->ply.plane.x = PLY_PLANE;
	else if (dir == EAST)
		gm->ply.plane.y = PLY_PLANE;
	else if (dir == SOUTH)
		gm->ply.plane.x = -PLY_PLANE;
	else if (dir == WEST)
		gm->ply.plane.y = -PLY_PLANE;
}

static void	get_ply_dir(t_gm *gm, int x, int y)
{
	if (gm->map.map[y][x] == 'N' || gm->map.map[y][x] == 'E'
		|| gm->map.map[y][x] == 'S' || gm->map.map[y][x] == 'W')
	{
		if (gm->ply.e_dir != NOTSET)
			c3d_fail_exit("Duplicated player position in map", NULL);
		if (gm->map.map[y][x] == 'N')
			set_dir(gm, NORTH, 0, -1);
		else if (gm->map.map[y][x] == 'E')
			set_dir(gm, EAST, 1, 0);
		else if (gm->map.map[y][x] == 'S')
			set_dir(gm, SOUTH, 0, 1);
		else if (gm->map.map[y][x] == 'W')
			set_dir(gm, WEST, -1, 0);
		gm->ply.pos.x = (double)x;
		gm->ply.pos.y = (double)y;
	}
}

void	c3d_check_map(t_gm *gm, int x, int y)
{
	int	error;

	error = 0;
	if (y < 0 || y >= gm->map.size.y || x < 0 || x >= gm->map.size.x)
		return ;
	if (gm->map.map[y][x] == '0' || gm->map.map[y][x] == 'N'
		|| gm->map.map[y][x] == 'E' || gm->map.map[y][x] == 'S'
		|| gm->map.map[y][x] == 'W' || gm->map.map[y][x] == 'D')
	{
		get_ply_dir(gm, x, y);
		if (gm->map.map[y][x] == 'D')
			gm->map.door_state = D_CLOSE;
		error += check_square(gm, x + 1, y);
		error += check_square(gm, x - 1, y);
		error += check_square(gm, x, y + 1);
		error += check_square(gm, x, y - 1);
		if (error)
			c3d_fail_exit("Map not surrounded by walls", NULL);
	}
	c3d_check_map(gm, x + 1, y);
	if (x == 0)
		c3d_check_map(gm, x, y + 1);
}
