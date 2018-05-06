/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:41:02 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/05 21:02:01 by ysibous          ###   ########.fr       */
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
	info->mlx_ptr = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx_ptr, 1000, 1000, "WOLF3D");
}

void	computer_ray_pos_and_dir(t_wolf *info, int x)
{
	info->camera.x = (double)(2 * x / (double)(WIN_WIDTH) - 1);
	info->ray_dir.x = (double)(info->dir.x + info->plane.x * info->camera.x);
	info->ray_dir.y = (double)(info->dir.y + info->plane.y * info->camera.x);
}

void	d_d_a(t_wolf *info)
{
	return ;
}

void	compute_positioning(t_wolf *info)
{
	
}

int		main()
{
	int		x;
	t_wolf	info;

	i = 0;
	init_wolf_info(&info);
	mlx_loop(info.mlx_ptr);
	while (x < WIN_WIDTH)
	{
		compute_ray_pos_and_dir(&info, x);

	}
}
