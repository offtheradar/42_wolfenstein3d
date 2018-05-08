/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vertex_init_info.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:17:39 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/07 18:47:47 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

t_2d_pixel	*create_2d_pix(double x, double y)
{
	t_2d_pixel	*pix;

	pix = (t_2d_pixel *)ft_memalloc(sizeof(t_2d_pixel));
	pix->x = x;
	pix->y = y;
	return (pix);
}

t_3d_pixel	*create_3d_pix(double x, double y, double z)
{
	t_3d_pixel *pix;

	pix = (t_3d_pixel *)ft_memalloc(sizeof(t_3d_pixel));
	pix->x = x;
	pix->y = y;
	pix->z = z;
	return (pix);
}

t_vertex	*create_vertex(double x, double y, double z)
{
	t_vertex *vertex;

	vertex = ft_memalloc(sizeof(t_vertex));
	vertex->local = create_3d_pix(x, y, z);
	vertex->world = create_3d_pix(0, 0, 0);
	vertex->aligned = create_3d_pix(0, 0, 0);
	vertex->projected = create_3d_pix(0, 0, 0);
	return (vertex);
}

t_info		*init_info(void)
{
	t_info	*info;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	info->plot = (t_plot *)ft_memalloc(sizeof(t_plot));
	info->plot->height = 0;
	info->plot->width = 0;
	info->plot->z_min = MAX_INT;
	info->plot->z_max = MIN_INT;
	info->mlx_ptr = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	info->theta = 0.5;
	info->phi = 0.0;
	info->psi = 0.0;
	info->scale = 0.5;
	info->sx = 1.0;
	info->sy = 1.0;
	info->sz = 1.0;
	info->tx = 0.0;
	info->ty = 0.0;
	info->tz = 0.0;
	init_rgb(info);
	info->colours = init_colours(info);
	info->focal_distance = 3.0;
	return (info);
}
