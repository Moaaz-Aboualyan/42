/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:28:20 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/20 19:21:55 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*buffer;
	char		*line;
	int			new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!leftover)
		leftover = ft_strdup("");
	new_line = find_new_line(fd, &leftover);
	if (new_line == -1)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	line = ft_substr(leftover, 0, new_line + 1);
	buffer = ft_substr(leftover, new_line + 1,
			ft_strlen(leftover) - new_line);
	free(leftover);
	leftover = buffer;
	return (line);
}

int	find_new_line(int fd, char **leftover)
{
	ssize_t		bytes_read;
	int			new_line;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	new_line = ft_strchr(*leftover, '\n');
	while (new_line == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		*leftover = ft_strjoin(*leftover, buffer);
		new_line = ft_strchr(*leftover, '\n');
	}
	free(buffer);
	if (!(*leftover) || (*leftover)[0] == '\0')
		return (-1);
	if (new_line == -1)
		return (ft_strlen(*leftover));
	return (new_line);
}
