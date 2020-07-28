/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 23:16:46 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/07/28 23:18:17 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char *s1, char *s2, int *err)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	s1l;
	size_t	s2l;

	if (!s1 || !s2)
		return (NULL);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (s1l + s2l + 1))))
	{
		*err = -1;
		return (NULL);
	}
	i = -1;
	j = 0;
	while (++i < (s1l + s2l))
		if (i < s1l)
			str[i] = s1[i];
		else
			str[i] = s2[j++];
	str[i] = '\0';
	return (str);
}

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

size_t		ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	if (destsize <= 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < destsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char		*ft_strnew(size_t size, int *err)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
	{
		*err = -1;
		return (NULL);
	}
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}
