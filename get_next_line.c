/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 23:16:01 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/07/29 22:34:26 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

int				free_str(char **s1, char **s2)
{
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (*s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (-1);
}

char			*fill_line(char *residue, char **line)
{
	char		*p_n;

	p_n = NULL;
	if (residue)
	{
		if ((p_n = ft_strchr(residue, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(residue);
			p_n++;
			ft_strcpy(residue, p_n);
		}
		else
		{
			*line = ft_strdup(residue);
			ft_strclr(residue);
		}
	}
	else
		*line = ft_strdup("");
	return (p_n);
}

void			trunc_line(char **line, char **residue, char **p_n, char **buf)
{
	char		*tmp;

	if ((*p_n = ft_strchr(*buf, '\n')))
	{
		**p_n = '\0';
		(*p_n)++;
		free(*residue);
		*residue = ft_strdup(*p_n);
	}
	tmp = *line;
	*line = ft_strjoin(*line, *buf);
	free(tmp);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*residue;
	char		*p_n;
	int			bwr;

	if (read(fd, NULL, 0) < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	bwr = 1;
	p_n = fill_line(residue, line);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (free_str(&buf, line));
	while (!p_n && (bwr = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (bwr < 0)
			return (free_str(&buf, &residue));
		buf[bwr] = '\0';
		trunc_line(line, &residue, &p_n, &buf);
	}
	free(buf);
	if (bwr == 0 && residue != 0)
		free_str(&residue, &residue);
	return ((p_n || bwr) ? 1 : 0);
}
