/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:50:19 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/27 23:29:27 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i] != 0)
			i++;
	return (i);
}

char		*ft_strdup(const char *s1, int *err)
{
	char	*str;

	str = (void *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str == NULL)
	{
		*err = -1;
		return (NULL);
	}
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
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
