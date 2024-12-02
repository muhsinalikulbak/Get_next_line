/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:52:51 by mkulbak           #+#    #+#             */
/*   Updated: 2024/12/02 15:18:57 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*newl(char * line)
{
	char	*new;
	int		i;

	i = 0;
	if (!line[0])
		return (NULL);
	while(line[i] && line[i] != '\n')
		i++;
	new = (char*)malloc(sizeof(char) * (i+2));
	if (!new)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*cut_line (char *line)
{
	char	*buffer;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	j = 0;
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	buffer = (char*)malloc(sizeof(char) * ft_strlen(line) - i);
	if (!buffer)
		return (NULL);
	i++;
	while (line[i])
		buffer[j++] = line[i++];
	buffer[j] = '\0';
	free(line);
	return (buffer);
}

char	*find_line(char *buffer, int fd)
{
	int		bytes;
	char	*read_buffer;

	read_buffer = malloc((sizeof(char) * (BUFFER_SIZE + 1)));
	if (!read_buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(read_buffer);
			free(buffer);
			return (NULL);
		}
		read_buffer[bytes] = '\0';
		if (bytes > 0)
		{
			buffer = ft_strjoin(buffer, read_buffer);
			if (!buffer)
				return (NULL);
			if (ft_strchr(buffer, '\n'))
				break;
		}
	}
	free(read_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{    
	static	char	*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = find_line(buffer, fd);
	if (!buffer)
		return (NULL);
	line = newl(buffer);
	buffer = cut_line(buffer);
	return (line);
}
