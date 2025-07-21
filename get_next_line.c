/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:04:41 by dasimoes          #+#    #+#             */
/*   Updated: 2025/07/20 20:59:44 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_line(char *buffer)
{
	int		i;
	int		size;
	char	*new_line;

	i = 0;
	size = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[size] && buffer[size] != '\n')
		size++;
	if (buffer[size] == '\n')
		size++;
	new_line = (char *)malloc((size + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	while (i < size)
	{
		new_line[i] = buffer[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

static char	*ft_extract_leftover(char *buffer)
{
	char	*left;
	int		i;
	int		j;

	i = 0;
	if (!buffer || !*buffer)
		return (NULL);
	j = ft_indexof(buffer, '\n');
	if (j == -1)
		return (NULL);
	left = (char *)malloc((ft_strlen(buffer) - j + 1) * sizeof(char));
	if (!left)
		return (NULL);
	j++;
	while (buffer[j + i])
	{
		left[i] = buffer[j + i];
		i++;
	}
	left[i] = '\0';
	return (left);
}

static char	*get_next_line_aux(int fd, char *line)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int	bytes;
	char	*next;

	next = line;
	bytes = 1;
	while ((ft_indexof(next, '\n') == -1) && (bytes > 0))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		buffer[bytes] = '\0';
		tmp = ft_strjoin(next, buffer);
		if (!tmp)
			return (ft_free(next));
		next = ft_free(next);
		next = tmp;
	}
	if (bytes < 0)
		return (NULL);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;
	char		*tmp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (left)
	{
		line = ft_strdup(left);
		left = ft_free(left);
	}
	line = get_next_line_aux(fd, line);
	tmp = line;
	left = ft_extract_leftover(tmp);
	line = ft_extract_line(tmp);
	tmp = ft_free(tmp);
	if (!line || !*line)
		return (ft_free(left));
	return (line);
}
