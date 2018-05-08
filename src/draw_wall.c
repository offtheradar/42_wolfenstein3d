/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:12:58 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/07 18:14:54 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	int_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		set_colour(t_wolf *info)
{
	if (info->world[(int)info->map.x][(int)info->map.y] == 1)
		return (0xFF0000);
	if (info->world[(int)info->map.x][(int)info->map.y] == 2)
		return (0xFFA500);
	if (info->world[(int)info->map.x][(int)info->map.y] == 3)
		return (0x0000FF);
	if (info->world[(int)info->map.x][(int)info->map.y] == 4)
		return (0xAFEEEE);
	return (0xFFFF00);
}

void	draw_vert_line(int x, int start, int end, t_wolf *info)
{
	if (start > end)
		int_swap(&start, &end);
	while (start != end)
	{
		mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, start, info->colour);
		start += 1;
	}
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
				(int)(-line_height / 2 + WIN_HEIGHT / 2) : 0;
	end = line_height / 2 + WIN_HEIGHT / 2 < WIN_HEIGHT ?
				(int)(line_height / 2 + WIN_HEIGHT / 2) : WIN_HEIGHT - 1;
	info->colour = set_colour(info);
	if (side == 1)
		info->colour /= 2;
	draw_vert_line(x, start, end, info);
}
