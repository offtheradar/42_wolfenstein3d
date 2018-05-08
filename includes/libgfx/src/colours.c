/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:47:29 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/07 18:48:02 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

int			*init_colours(t_info *info)
{
	int		*colours;
	int		i;
	float	f;
	int		rgb[3];

	info->num_colours = 100;
	colours = (int *)ft_memalloc(sizeof(int) * info->num_colours);
	f = 0;
	i = 0;
	while (i < info->num_colours)
	{
		rgb[0] = (cos(f) + info->r) * 127;
		rgb[1] = (sin(f) + info->g) * 127;
		rgb[2] = (-cos(f) + info->b) * 127;
		colours[i] = ((int)rgb[2]) << 16 | ((int)rgb[1]) << 8 | rgb[0];
		f += M_PI / info->num_colours;
		i++;
	}
	return (colours);
}

void		init_rgb(t_info *info)
{
	info->r = 255;
	info->g = 192;
	info->b = 203;
}
