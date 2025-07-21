/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:05:03 by dasimoes          #+#    #+#             */
/*   Updated: 2025/07/20 20:57:25 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		size;
	char	*result;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size = (ft_strlen(s1) + ft_strlen(s2) + 1);
	result = (char *)malloc(size * sizeof(char));
	if (!result)
		return (NULL);
	while (s1[i])
		result[i] = s1[i++];
	while (s2[j])
		result[i + j] = s2[j++];
	result[size - 1] = '\0';
	return (result);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		size;
	char	*dup;

	i = 0;
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	dup = (char *)malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < size)
		dup[i] = str[i++];
	dup[size] = '\0';
	return (dup);
}

int	ft_indexof(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
