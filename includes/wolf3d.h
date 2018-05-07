/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:47:08 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/06 19:09:13 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# include "libgfx/libgfx.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef struct	s_wolf
{
	t_2d_pixel	pos;
	t_2d_pixel	dir;
	t_2d_pixel	plane;
	t_2d_pixel	camera;
	t_2d_pixel	ray_dir;
	t_2d_pixel	map;
	t_2d_pixel	side_dist;
	t_2d_pixel	delta;
	t_2d_pixel	step;
	int			width;
	int			height;
	int			colour;
	int			**world;
	void		*mlx_ptr;
	void		*mlx_win;
	double		curr_time;
	double		prev_time;
}				t_wolf;

/*
******************************** Initialize Wolf Info **************************
*/

void			init_wolf_info(t_wolf *info);

/*
******************************** Raycaster Computations ************************
*/

void			compute_ray_pos_and_dir(t_wolf *info, int x);

void			compute_positioning(t_wolf *info);

void			init_compute_side_dist(t_wolf *info);

int				d_d_a(t_wolf *info);

int				compute_wall_dist_line_height(t_wolf *info, int side);

void			draw_vert_line(int x, int start, int end, t_wolf *info);

void			draw_wall(t_wolf *info, int x);
/*
******************************** Load File *************************************
*/

int				open_file(char *file_name);

t_list			*load_file(t_wolf *info, int fd);

void			convert_lst_to_arr_helper(t_wolf *info, char **buff, int y);

void			convert_lst_to_arr(t_wolf *info, t_list *lst);

void			create_world(t_wolf *info, char *filename);

#endif