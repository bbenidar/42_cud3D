/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:50:18 by moudrib           #+#    #+#             */
/*   Updated: 2023/08/10 10:07:15 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save_rest(char *buf)
{
	char	*rest;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (buf[++i])
	{
		if (buf[i] == '\n')
		{
			i++;
			break ;
		}
	}
	rest = malloc(((ft_strlen(buf) - i) + 1) * sizeof(char));
	if (!rest)
		return (free(buf), NULL);
	while (buf[i])
		rest[j++] = buf[i++];
	rest[j] = '\0';
	return (free(buf), rest);
}

char	*ft_read_line(int fd, char *buf)
{
	char	*tmp;
	int		read_return;

	read_return = 1;
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (ft_search_newline(buf) && read_return)
	{
		read_return = read(fd, tmp, BUFFER_SIZE);
		if ((read_return == 0 && !buf) || read_return < 0)
			return (free(tmp), free(buf), NULL);
		tmp[read_return] = '\0';
		buf = ft_strjoin(buf, tmp);
	}
	free(tmp);
	if (buf[0] == '\0')
		return (free(buf), NULL);
	return (buf);
}

char	*ft_get_next_line(int fd)
{
	static char		*buf;
	char			*line;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read_line(fd, buf);
	if (!buf)
		return (NULL);
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
		{
			i++;
			break ;
		}
	}
	line = ft_substr(buf, 0, i);
	buf = ft_save_rest(buf);
	return (line);
}
