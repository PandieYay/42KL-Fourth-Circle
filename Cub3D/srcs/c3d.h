/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:41:54 by schuah            #+#    #+#             */
/*   Updated: 2022/12/07 17:44:00 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_H
# define C3D_H

# include "../libft/srcs/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>

/* Mac key codes */
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_E		14
# define KEY_M		46
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define EXIT_EVENT	17
# define KD_EVENT	2
# define KEY_PRESS	1
# define EXIT_MASK	0

/* Map settings */
# define WIN_W		1280
# define WIN_H		800
# define MMAP_W		15
# define MMAP_H		15
# define MMAP_PX	15
# define TEXT_W		64
# define TEXT_H		64

/* Player prefs */
# define PLY_MVSPD	0.25
# define PLY_ROTSPD	0.05
# define PLY_PLANE	1
# define DOOR_SPD	25

/* Self defined */
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define TBROWN		0x80964B00
# define TGREY		0x80808080
# define TWHITE		0x80FFFFFF
# define TBLACK		0x80000000
# define TRANS		0xFF000000
# define D_OPEN		0
# define D_CLOSE	1

/**
 * @brief Double vector struct
 * 
 * @param x X value in double
 * @param y Y value in double
 */
typedef struct s_dvct
{
	double	x;
	double	y;
}	t_dvct;

/**
 * @brief Int vector struct
 * 
 * @param x X value in int
 * @param y Y value in int
 */
typedef struct s_ivct
{
	int	x;
	int	y;
}	t_ivct;

/**
 * @brief RGB struct
 * 
 * @param r Red value
 * @param g Green value
 * @param b Blue value
 * @param hex Hex value converted using RGB
 */
typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				hex;
}	t_rgb;

/**
 * @brief Image struct
 * 
 * @param ref Image reference
 * @param addr Address of image
 * @param bpp Bits per pixel of image
 * @param sl Size line of image
 * @param end Endian of image
 * @param size Image size
 */
typedef struct s_img
{
	void	*ref;
	char	*addr;
	int		bpp;
	int		sl;
	int		end;
	t_ivct	size;
}	t_img;

/**
 * @brief Window struct
 * 
 * @param ref Window reference
 * @param frame Current frame
 * @param size Image size
 * @param playing Whether an animation is playing
 * @param mouse Mouse state
 */
typedef struct s_win
{
	void	*ref;
	int		frame;
	int		mouse;
	int		playing;
	t_ivct	size;
}	t_win;

/**
 * @brief Door struct
 * 
 * @param pos Door position
 * @param next Next node
 */
typedef struct s_door
{
	t_ivct			pos;
	struct s_door	*next;
}	t_door;

/**
 * @brief Map struct
 * 
 * @param c_rgb Ceiling RGB values
 * @param f_rgb Floor RGB values
 * @param n_img North wall texture
 * @param e_img East wall texture
 * @param s_img South wall texture
 * @param w_img West wall texture
 * @param d_img Door texture
 * @param main Main image of the map
 * @param mini Minimap image of the map taken from main
 * @param door Door linked list
 * @param map Map array to be rendered in 2D
 * @param map_raw Map array taken from file in 2D
 * @param size Map size
 * @param imgw Image whole after rendering
 */
typedef struct s_map
{
	t_rgb	c_rgb;
	t_rgb	f_rgb;
	t_img	n_img;
	t_img	e_img;
	t_img	s_img;
	t_img	w_img;
	t_img	d_img;
	t_img	*main;
	t_img	*mini;
	t_img	imgw;
	t_ivct	size;
	int		door_state;
	char	**map;
}	t_map;

/**
 * @brief Player struct
 * 
 * @param e_dir Direction player is facing at in enum
 * @param dir Vector direction of where the player is facing
 * @param c_dir Constant vector direction of where the player is facing
 * @param pos Position of the player on the map
 * @param plane	View plane of the player
 */
typedef struct s_ply
{
	enum
	{
		NOTSET,
		NORTH,
		EAST,
		SOUTH,
		WEST
	}	e_dir;
	t_dvct	dir;
	t_dvct	c_dir;
	t_dvct	pos;
	t_dvct	plane;
}	t_ply;

/**
 * @brief Render struct
 * 
 * @param delta_dist Delta distance vector
 * @param side_dist	Side distance vector
 * @param offset Offset vector
 * @param raydir Ray direction vector
 * @param step Step vector
 * @param map Map vector
 * @param perp_wall_dist Perpendicular wall distance vector
 * @param camera_x X axis of the camera
 * @param wall_x X axis of the wall
 * @param line_h Line height
 * @param d_start Y axis for starting draw pos
 * @param d_end Y axis for end draw pos
 * @param tex_x X axis for texture
 * @param side Side value
 * @param hit Hit value
 */
typedef struct s_render
{
	t_dvct	delta_dist;
	t_dvct	side_dist;
	t_dvct	offset;
	t_dvct	raydir;
	t_dvct	step;
	t_ivct	map;
	double	perp_wall_dist;
	double	camera_x;
	double	wall_x;
	int		line_h;
	int		d_start;
	int		d_end;
	int		tex_x;
	int		side;
	int		hit;
}	t_render;

/**
 * @brief Gamemaster struct
 *
 * @param mlx Main mlx reference
 * @param win Window struct
 * @param map Map struct
 * @param ply Player struct
 */
typedef struct s_gm
{
	void		*mlx;
	t_win		win;
	t_map		map;
	t_ply		ply;
	t_render	render;
}	t_gm;

void	c3d_init_gm(t_gm *gm);

void	c3d_get_map(t_gm *gm, char *str, int fd);

void	c3d_orient_map(t_gm *gm);

void	c3d_check_file(t_gm *gm, int ac, char **av);
void	c3d_check_map(t_gm *gm, int x, int y);

void	c3d_all_elements_present(t_gm *gm);
int		c3d_map_contents_only(char *str);
int		c3d_is_all_num(char *str1, char *str2, char *str3);
void	c3d_trim_spaces(char *str, int len);
char	*c3d_pad_spaces(t_gm *gm, char *str);

int		c3d_fail_exit(char *msg, char *details);
int		c3d_success_exit(void);

void	c3d_hooks(t_gm *gm);

int		c3d_display(t_gm *gm);
void	c3d_display_minimap(t_gm *gm);

void	c3d_color_block(t_gm *gm, t_ivct cur, unsigned int color);
void	c3d_copy_main(t_gm *gm, int src_pixel, int x, int y);
void	c3d_color_image(t_gm *gm, t_img *img, int color);

void	c3d_player_vertical_movement(t_gm *gm, int keycode);
void	c3d_player_horizontal_movement(t_gm *gm, int keycode);
void	c3d_player_view(t_gm *gm, int keycode);
void	c3d_mouse_state(t_gm *gm, int keycode);
void	c3d_mouse_control(t_gm *gm);

void	c3d_door_state(t_gm *gm, int keycode);
void	c3d_update_door(t_gm *gm);

void	c3d_render(t_gm *gm);
void	c3d_renderdoor(t_gm *gm);
void	c3d_my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	c3d_draw_verline(t_img *img, int i, t_gm *gm);
void	c3d_set_variables(t_gm *gm, int x);
void	c3d_check_steps(t_gm *gm);
void	c3d_set_length(t_gm *gm);
void	c3d_check_sides(t_gm *gm, t_img *curimg);

#endif
