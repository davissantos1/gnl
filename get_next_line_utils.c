#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	int	size;
	char	*result;

	i = 0;
	j = 0;
	size = (ft_strlen(s1) + ft_strlen(s2) + 1);
	result = (char *)malloc(size * sizeof(char));
	if (!result)
		return (NULL);
	while (s1[i])
		result[i] = s1[i++];
	while (s2[j])
		result[i +j] = s2[j++];
	result[size - 1] = '\0';
	return (result);
}
