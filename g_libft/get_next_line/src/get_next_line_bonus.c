/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:56:12 by aoger             #+#    #+#             */
/*   Updated: 2024/12/09 18:51:16 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"

char	*trim_buffer(char *buffer)
{
	char	*new_buffer;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	if (!buffer[i])
		return (free(buffer), NULL);
	++i;
	new_buffer = malloc(ft_strlen(buffer + i) + 1);
	if (!new_buffer)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	size_t	len;

	if (!buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		++len;
	if (buffer[len] == '\n')
		++len;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, len);
	line[len] = '\0';
	return (line);
}

char	*read_file_append_buffer(int fd, char *buffer)
{
	char	*read_file;
	ssize_t	bytes_read;

	read_file = malloc(BUFFER_SIZE + 1);
	if (!read_file)
		return (free(buffer), NULL);
	while (1)
	{
		bytes_read = read(fd, read_file, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(read_file), free(buffer), NULL);
		if (bytes_read == 0)
			break ;
		read_file[bytes_read] = '\0';
		buffer = ft_strjoin_gnl(buffer, read_file);
		if (!buffer)
			return (free(read_file), NULL);
		if (ft_strchr(read_file, '\n'))
			break ;
	}
	free(read_file);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = NULL;
	buffer[fd] = read_file_append_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (!*buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = extract_line(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = trim_buffer(buffer[fd]);
	return (line);
}
