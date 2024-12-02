#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*find_line(char *buffer, int fd);
char	*cut_line (char *line);
char	*newl(char * line);
#endif
