/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:04:41 by dasimoes          #+#    #+#             */
/*   Updated: 2025/07/18 23:30:03 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer[BUFFER_SIZE];
	int	bytes_read;

	bytes_read = 1;
	while (!(ft_strchr(buffer, '\n')) && bytes_read)
	{
		
		bytes_read = read(fd, buffer, BUFFER_SIZE);
}
