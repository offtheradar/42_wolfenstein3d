/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:05:58 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/07 18:30:27 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		move_player(int keycode, t_wolf *info)
{
	if (keycode == 53)
		exit(0);
	if (keycode == UP)
		move(info, 1);
	if (keycode == DOWN)
		move(info, -1);
	if (keycode == LEFT)
		rotate(info, 1);
	if (keycode == RIGHT)
		rotate(info, -1);
	return (1);
}

void	move(t_wolf *info, int sign)
{
	if (info->world[(int)(info->pos.x + sign *
					(info->dir.x * SPEED))][(int)info->pos.y] == 0)
		info->pos.x += sign * (info->dir.x * SPEED);
	if (info->world[(int)info->pos.x][(int)(info->pos.y + sign * (info->dir.y *
																SPEED))] == 0)
		info->pos.y += sign * (info->dir.y * SPEED);
	ray_cast(info);
}

void	rotate(t_wolf *info, int sign)
{
	double tmp;

	tmp = info->dir.x;
	info->dir.x = info->dir.x * cos(sign * ROT) - info->dir.y * sin(sign * ROT);
	info->dir.y = tmp * sin(sign * ROT) + info->dir.y * cos(sign * ROT);
	tmp = info->plane.x;
	info->plane.x = info->plane.x * cos(sign * ROT) - info->plane.y *
														sin(sign * ROT);
	info->plane.y = tmp * sin(sign * ROT) + info->plane.y * cos(sign * ROT);
	ray_cast(info);
}
