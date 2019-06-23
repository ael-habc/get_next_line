/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-habc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:22:39 by ael-habc          #+#    #+#             */
/*   Updated: 2019/06/22 23:56:51 by ael-habc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_break_index(char *rest)
{
	int	i;

	i = 0;
	while (rest[i] != '\n' && rest[i])
		i++;
	return (i);
}

int		store_rest(const int fd, char **rest)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(*rest, buff);
		ft_strdel(rest);
		*rest = tmp;
		if ((ft_strchr(buff, '\n')))
			break ;
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*rest[4865];
	int			br_index;
	char		*tmp;

	if (fd < 0 || fd > 4864 || !line)
		return (-1);
	if (!rest[fd])
		rest[fd] = ft_strnew(0);
	tmp = ft_strdup(rest[fd]);
	ft_strdel(&rest[fd]);
	if ((ret = store_rest(fd, &tmp) < 0))
		return (-1);
	br_index = ft_break_index(tmp);
	*line = ft_strsub(tmp, 0, br_index);
	if (tmp[br_index])
		rest[fd] = ft_strdup(tmp + br_index + 1);
	ft_strdel(&tmp);
	if (ret == 0 && !rest[fd] && **line == '\0')
		return (0);
	return (1);
}
