#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// External includes
# include <stdlib.h>
# include <fcntl.h>

// Macro default definition
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

// Function prototypes
char *get_next_line(int fd);

#endif
