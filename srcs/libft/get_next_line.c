/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:05:31 by yuxu              #+#    #+#             */
/*   Updated: 2018/04/30 14:35:09 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*joinfree(char *s, char *buf, int rd)
{
	char	*res;

	buf[rd] = '\0';
	if (s == NULL)
		s = "";
	res = ft_strjoin(s, buf);
	if (s[0] != '\0')
		free(s);
	return (res);
}

int		ft_read_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				rd;
	static char		*s = NULL;

	while (ft_index(s, '\n') == -1 && (rd = read(fd, buf, BUFF_SIZE)) > 0)
		s = joinfree(s, buf, rd);
	if (s != NULL && rd <= BUFF_SIZE && ft_index(s, '\n') == -1)
	{
		*line = ft_strdup(s);
		if (s != NULL && *s)
			rd = 1;
		s = ft_strmove(s, ft_strlen(s));
	}
	if (s != NULL && ft_index(s, '\n') >= 0)
	{
		*line = ft_partstr(s, 0, '\n');
		s = ft_strmove(s, (ft_partlen(s, 0, '\n') + 1));
		rd = 1;
	}
	return (rd);
}

int		get_next_line(int const fd, char **line)
{
	int rd;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if ((rd = ft_read_line(fd, line)) == -1)
		return (-1);
	if (rd == 0)
		return (0);
	if (rd > 0)
		return (1);
	return (-1);
}
