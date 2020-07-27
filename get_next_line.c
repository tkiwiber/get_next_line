/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:58:23 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/27 23:46:32 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

char			*ft_strcpy(char *dest, char *src)
{
	int			i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_strchr(const char *s, int c)
{
	char		*str_p;

	str_p = (char *)s;
	while (*str_p != '\0')
	{
		if (*str_p == (unsigned char)c)
			return (str_p);
		str_p++;
	}
	if (*str_p == (unsigned char)c)
		return (str_p);
	else
		return (NULL);
}

char			*fill_line(char *residue, char **line, int *err)
{
	char		*p_n;

	*err = 1;
	if (!(line))
		*err = -1;
	p_n = NULL;
	if (residue)
	{
		if ((p_n = ft_strchr(residue, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(residue, err);
			ft_strcpy(residue, ++p_n);
		}
		else
		{
			*line = ft_strdup(residue, err);
			ft_strclr(residue);
		}
	}
	else if (*err != -1)
		*line = ft_strnew(1, err);
	return (p_n);
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*residue;
	char		*p_n;
	char		*tmp;
	int			err;

	if ((read(fd, NULL, 0) == -1) || (!line) || (BUFFER_SIZE < 1))
		return (-1);
	p_n = fill_line(residue, line, &err);
	while (!p_n && err != -1 && (err = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[err] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n++ = '\0';
			free(residue);
			residue = ft_strdup(p_n, &err);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf, &err);
		free(tmp);
	}
	if (err == -1)
		return (-1);
	return ((ft_strlen(residue) || err) ? 1 : 0);
}
