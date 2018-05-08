/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:41:02 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/07 19:11:07 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ray_cast(t_wolf *info)
{
	int x;

	x = 0;
	mlx_clear_window(info->mlx_ptr, info->mlx_win);
	while (x < WIN_WIDTH)
	{
		compute_ray_pos_and_dir(info, x);
		compute_positioning(info);
		init_compute_side_dist(info);
		draw_wall(info, x);
		x++;
	}
}

int		clean_exit(void)
{
	exit(1);
	return (1);
}

int		main(int ac, char **av)
{
	t_wolf	info;

	if (ac != 2)
		ft_putstr_fd("Usage: ./wolf3d file_name", 2);
	init_wolf_info(&info);
	create_world(&info, av[1]);
	ray_cast(&info);
	mlx_key_hook(info.mlx_win, move_player, &info);
	mlx_hook(info.mlx_win, 17, 0, clean_exit, &info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
