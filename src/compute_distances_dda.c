/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_distances_dda.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:20:21 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/07 18:22:23 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	compute_ray_pos_and_dir(t_wolf *info, int x)
{
	info->camera.x = (double)(2.0 * x / (double)(WIN_WIDTH) - 1.0);
	info->ray_dir.x = (double)(info->dir.x + info->plane.x * info->camera.x);
	info->ray_dir.y = (double)(info->dir.y + info->plane.y * info->camera.x);
}

void	compute_positioning(t_wolf *info)
{
	info->map.x = (int)info->pos.x;
	info->map.y = (int)info->pos.y;
	info->delta.x = (double)fabs(1.0 / info->ray_dir.x);
	info->delta.y = (double)fabs(1.0 / info->ray_dir.y);
}

void	init_compute_side_dist(t_wolf *info)
{
	if (info->ray_dir.x < 0)
	{
		info->step.x = -1;
		info->side_dist.x = (info->pos.x - info->map.x) * info->delta.x;
	}
	else
	{
		info->step.x = 1;
		info->side_dist.x = (info->map.x + 1.0 - info->pos.x) * info->delta.x;
	}
	if (info->ray_dir.y < 0)
	{
		info->step.y = -1;
		info->side_dist.y = (info->pos.y - info->map.y) * info->delta.y;
	}
	else
	{
		info->step.y = 1;
		info->side_dist.y = (info->map.y + 1.0 - info->pos.y) * info->delta.y;
	}
}

int		d_d_a(t_wolf *info)
{
	int hit;
	int side;

	hit = 0;
	side = 0;
	while (!hit)
	{
		if (info->side_dist.x < info->side_dist.y)
		{
			info->side_dist.x += info->delta.x;
			info->map.x += info->step.x;
			side = 0;
		}
		else
		{
			info->side_dist.y += info->delta.y;
			info->map.y += info->step.y;
			side = 1;
		}
		if (info->world[(int)info->map.x][(int)info->map.y])
			hit = 1;
	}
	return (side);
}

int		compute_wall_dist_line_height(t_wolf *info, int side)
{
	double	wall_dist;
	int		line_height;

	line_height = 0;
	wall_dist = 0;
	if (side)
		wall_dist = (info->map.y - info->pos.y + (1.0 - (double)info->step.y)
						/ 2.0) / info->ray_dir.y;
	else
		wall_dist = (info->map.x - info->pos.x + (1.0 - (double)info->step.x) /
						2.0) / info->ray_dir.x;
	line_height = (int)(WIN_HEIGHT / wall_dist);
	return (line_height);
}
