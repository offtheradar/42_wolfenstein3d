/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:41:02 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/06 16:04:47 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_wolf_info(t_wolf *info)
{
	info->pos.x = 22;
	info->pos.y = 12;
	info->dir.x = -1;
	info->dir.y = 0;
	info->plane.x = 0;
	info->plane.y = 0.66;
	info->curr_time = 0;
	info->prev_time = 0;
	info->camera.x = 0;
	info->camera.y = 0;
	info->ray_dir.x = 0;
	info->ray_dir.y = 0;
	info->map.x = 0;
	info->map.x = 0;
	info->step.x = 0;
	info->step.y = 0;
	info->mlx_ptr = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx_ptr, 1000, 1000, "WOLF3D");
}

void	computer_ray_pos_and_dir(t_wolf *info, int x)
{
	info->camera.x = (double)(2.0 * x / (double)(WIN_WIDTH) - 1.0);
	info->ray_dir.x = (double)(info->dir.x + info->plane.x * info->camera.x);
	info->ray_dir.y = (double)(info->dir.y + info->plane.y * info->camera.x);
}

void	compute_positioning(t_wolf *info)
{
	info->map.x = (int)info->pos.x;
	info->map.y = (int)info->pos.y;
	info->delta.x = abs(1.0 / info->ray_dir.x);
	info->delta.y = abs(1.0 / info->ray_dir.y);
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
		if (info->world[(int)info->map.y][(int)info->map.x])
			hit = 1;
	}
	return (side);
}

int		compute_wall_dist_line_height(t_wolf *info, int side)
{
	int wall_dist;

	wall_dist = 0;
	if (side)
		wall_dist = (info->map.y - info->pos.y + (1 - info->step.y) / 2) /
						info->ray_dir.y;
	else
		wall_dist = (info->map.y - info->pos.y + (1 - info->step.y) / 2) /
						info->ray_dir.y;
	return ((int)(WIN_HEIGHT / wall_dist));
}

void	draw_wall(t_wolf *info, int x)
{
	int		start;
	int		end;
	int		side;
	int		line_height;

	side = d_d_a(info);
	line_height = compute_wall_dist_line_height(info, side);
	start = -line_height / 2 + WIN_HEIGHT / 2 > 0 ?
				-line_height / 2 + WIN_HEIGHT / 2 : 0;
	end = line_height / 2 + WIN_HEIGHT / 2 < WIN_HEIGHT ?
				line_height / 2 + WIN_HEIGHT / 2 : WIN_HEIGHT;
	
}

int		main(void)
{
	int		x;
	int		hit;
	int		side;
	t_wolf	info;

	x = 0;
	hit = 0;
	init_wolf_info(&info);
	mlx_loop(info.mlx_ptr);
	while (x < WIN_WIDTH)
	{
		compute_ray_pos_and_dir(&info, x);
		compute_positioning(&info);
		init_compute_side_dist(&info);
		draw_wall(&info, x);
	}
}
