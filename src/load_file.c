/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:40:57 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/06 19:08:47 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
**Safely open the file
*/

int		open_file(char *file_name)
{
	int fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putstr("File Error!");
		exit(0);
	}
	return (fd);
}

/*
** Loads the file to a list of strings, and then converts the string
** to an array of int's.
*/

t_list	*load_file(t_wolf *info, int fd)
{
	char	*buff;
	t_list	*list;
	int		result;

	list = NULL;
	info->width = -1;
	info->height = 0;
	while ((result = get_next_line(fd, &buff)) > 0)
	{
		if (info->width == -1)
			info->width = ft_count_words(buff, ' ');
		ft_lst_add_to_end(ft_lstnew(buff, ft_strlen(buff) + 1), &list);
		free(buff);
		(info->height)++;
	}
	return (list);
}

/*
** Convert the list of strings to a 3D matrix, initializing local, world and
** aligned coordinates.
*/

void	convert_lst_to_arr_helper(t_wolf *info, char **buff, int y)
{
	int x;
	int	z;

	x = -1;
	z = 0;
	while (++x < info->width && buff[x])
	{
		z = ft_atoi(buff[x]);
		info->world[y][x] = z;
	}
}

void	convert_lst_to_arr(t_wolf *info, t_list *lst)
{
	int		y;
	t_list	*tmp;
	char	**buff;

	info->world = (int **)ft_memalloc(sizeof(int *) * info->height);
	tmp = lst;
	y = -1;
	while (++y < info->height && lst)
	{
		info->world[y] = (int *)ft_memalloc(sizeof(int) * info->width);
		buff = ft_strsplit(tmp->content, ' ');
		convert_lst_to_arr_helper(info, buff, y);
		ft_free_doublep(buff);
		tmp = tmp->next;
	}
	free(tmp);
	ft_free_lst(lst);
}

/*
** Creates matrix with local coordinates.
*/

void	create_world(t_wolf *info, char *filename)
{
	int fd;

	fd = open_file(filename);
	convert_lst_to_arr(info, load_file(info, fd));
	close(fd);
}
