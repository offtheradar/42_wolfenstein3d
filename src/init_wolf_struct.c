/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wolf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:11:48 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/07 18:12:08 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_wolf_info(t_wolf *info)
{
	info->pos.x = 3;
	info->pos.y = 3;
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
	info->side_dist.x = 0;
	info->side_dist.y = 0;
	info->width = 0;
	info->height = 0;
	info->mlx_ptr = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
									"WOLF3D");
}
