/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 23:16:26 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/07/29 22:31:00 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
int		get_next_line(int fd, char **line);
int		free_str(char **s1, char **s2);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(const char *s, int c);
char	*fill_line(char *root, char **line);
void	ft_strclr(char *s);
void	trunc_line(char **line, char **residue, char **p_n, char **buf);

#endif
