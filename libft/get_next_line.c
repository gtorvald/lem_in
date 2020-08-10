/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:11:00 by fmelda            #+#    #+#             */
/*   Updated: 2020/01/21 14:13:30 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_search_n(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*change(char **buf)
{
	char	*ptr;
	char	*temp;
	int		i;
	int		len;

	len = 0;
	if (*buf)
		len = ft_strlen(*buf);
	temp = ft_memchr(*buf, '\n', len);
	i = temp - *buf;
	if ((ptr = (char *)malloc(sizeof(char) * (i + 1))))
	{
		ft_memcpy(ptr, *buf, i);
		ptr[i] = '\0';
		temp = *buf;
		*buf = ft_strsub(*buf, i + 1, len);
		free(temp);
		return (ptr);
	}
	return (NULL);
}

static int	too_many_lines(char **buf, char **line, int fd, int res)
{
	if (ft_search_n(buf[fd]))
	{
		*line = change(&buf[fd]);
		return (1);
	}
	if (res == 0 && ft_strlen(buf[fd]))
	{
		*line = buf[fd];
		buf[fd] = NULL;
		return (1);
	}
	return (-1);
}

static int	check(char **buf, char *tmp, int fd)
{
	if (!(buf[fd] = ft_strjoin(buf[fd], tmp)))
	{
		free(buf[fd]);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf[12000];
	int			res;
	char		tmp[BUFF_SIZE + 1];
	char		*tmp2;

	if (!line || BUFF_SIZE <= 0 || fd < 0
	|| fd > 12000 || (res = read(fd, tmp, 0)) < 0)
		return (-1);
	if (buf[fd] == NULL)
		buf[fd] = ft_strnew(1);
	while ((res = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[res] = '\0';
		tmp2 = buf[fd];
		if (check(buf, tmp, fd) == 1)
			return (-1);
		free(tmp2);
		if (ft_search_n(buf[fd]))
			break ;
	}
	if (too_many_lines(buf, line, fd, res) == 1)
		return (1);
	return (0);
}
