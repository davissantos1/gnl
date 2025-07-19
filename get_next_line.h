/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:04:53 by dasimoes          #+#    #+#             */
/*   Updated: 2025/07/18 22:09:13 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// External includes
# include <stdlib.h>
# include <fcntl.h>

// Macro default definition
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

# endif

// Function prototypes
char	*get_next_line(int fd);

#endif
