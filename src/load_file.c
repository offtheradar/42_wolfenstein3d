/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:40:57 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/06 18:24:25 by ysibous          ###   ########.fr       */
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

t_list	*load_file(int fd)
{
	char	*buff;
	t_list	*list;
	int		result;

	list = NULL;
	while ((result = get_next_line(fd, &buff)) > 0)
	{
		ft_lst_add_to_end(ft_lstnew(buff, ft_strlen(buff) + 1), &list);
		free(buff);
	}
	return (list);
}

