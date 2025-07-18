#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer[BUFFER_SIZE];
	int	bytes_read;

	bytes_read = 1;
	while (bytes_read)
		bytes_read = read(fd, buffer, BUFFER_SIZE);
}
