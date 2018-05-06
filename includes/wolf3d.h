/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:47:08 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/05 21:00:51 by ysibous          ###   ########.fr       */
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
	t_2d_pixel	step;
	void		*mlx_ptr;
	void		*mlx_win;
	double		curr_time;
	double		prev_time;
}				t_wolf;
#endif

/*
******************************** Initialize Wolf Info **************************
*/

void			init_wolf_info(t_wolf *info);

/*
******************************** Raycaster Computations ************************
*/

void			computer_ray_pos_and_dir(t_wolf *info, int x);

/*
******************************** Raycaster Computations ************************
*/

