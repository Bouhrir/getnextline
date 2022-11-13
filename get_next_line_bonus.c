/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:24:40 by obouhrir          #+#    #+#             */
/*   Updated: 2022/11/13 14:14:33 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_buff(int fd, char *arc)
{
	char	*buff;
	int		i;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			free(arc);
			free(buff);
			return (NULL);
		}
		if (i == 0)
			break ;
		buff[i] = '\0';
		arc = ft_join(arc, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (arc);
}

char	*get_befor(char *arc)
{
	char	*line;
	int		i;

	i = 0;
	while (arc[i] && arc[i] != '\n')
		i++;
	if (arc[i] == '\n')
		i++;
	line = ft_substr(arc, 0, i);
	return (line);
}

char	*get_after(char *arc)
{
	char	*new_arc;
	int		i;

	i = 0;
	while (arc[i] && arc[i] != '\n')
		i++;
	if (arc[i] == '\n')
		i++;
	if (arc[i] == 0)
	{
		free(arc);
		return (NULL);
	}
	new_arc = ft_substr(arc, i, lenth(arc) - i);
	free(arc);
	return (new_arc);
}

char	*get_next_line(int fd)
{
	char static	*arc[OPEN_MAX];
	char		*line;

	if (fd == 1 || fd == 2 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	arc[fd] = get_buff(fd, arc[fd]);
	if (!(arc[fd]))
		return (NULL);
	line = get_befor(arc[fd]);
	arc[fd] = get_after(arc[fd]);
	return (line);
}
