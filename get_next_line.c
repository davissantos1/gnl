/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:04:41 by dasimoes          #+#    #+#             */
/*   Updated: 2025/07/19 17:12:50 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	line[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		buffer[BUFFER_SIZE];
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	line = NULL;
	if (fd < 0)
		return (NULL);
	while (ft_strlen(leftover) != bytes_read)
		bytes_read = read(fd, buffer, 1);
	while (!(ft_strchr(buffer, '\n')) && bytes_read)
	{
		line = ft_strjoin(line, buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
	}
	line = ft_extract_line(line);
	leftover = ft_strdup(line);
	return (line);
}
