/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:58:46 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/12 12:32:49 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

typedef struct s_fd_buffer
{
	int					fd;
	char				*buffer;
	struct s_fd_buffer	*next;
}	t_fd_buffer;

static t_fd_buffer	*get_fd_node(t_fd_buffer **head, int fd)
{
	t_fd_buffer	*curr;
	t_fd_buffer	*new_node;

	curr = *head;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		curr = curr->next;
	}
	new_node = malloc(sizeof(t_fd_buffer));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->buffer = NULL;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

static void	remove_fd_node(t_fd_buffer **head, int fd)
{
	t_fd_buffer	*curr;
	t_fd_buffer	*prev;

	curr = *head;
	prev = NULL;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				*head = curr->next;
			free(curr->buffer);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

static char	*extract_line(char **buffer)
{
	char	*newline_pos;
	char	*line;
	char	*leftover;
	size_t	line_len;
	size_t	i;

	newline_pos = ft_strchr(*buffer, '\n');
	if (newline_pos)
	{
		line_len = newline_pos - *buffer + 1;
		line = malloc(line_len + 1);
		if (!line)
			return (NULL);
		i = 0;
		while (i < line_len)
		{
			line[i] = (*buffer)[i];
			i++;
		}
		line[line_len] = '\0';
		leftover = ft_strdup(*buffer + line_len);
		free(*buffer);
		*buffer = leftover;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fd_buffer	*head;
	t_fd_buffer			*node;
	char				*temp_buffer;
	ssize_t				bytes_read;
	char				*tmp;

	head = NULL;
	temp_buffer = malloc((BUFFER_SIZE + 1) * suzeof(char *));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_fd_node(&head, fd);
	if (!node->buffer)
		node->buffer = ft_strdup("");
	if (!node)
		return (NULL);
	while (!ft_strchr(node->buffer, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			remove_fd_node(&head, fd);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		tmp = ft_strjoin(node->buffer, temp_buffer);
		free(node->buffer);
		node->buffer = tmp;
		if (!node->buffer)
		{
			remove_fd_node(&head, fd);
			return (NULL);
		}
	}
	if (!node->buffer || node->buffer[0] == '\0')
	{
		remove_fd_node(&head, fd);
		return (NULL);
	}
	return (extract_line(&node->buffer));
}

int	main(void)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*line2;

	fd = open("hello.txt", O_RDONLY);
	fd2 = open("hello2.txt", O_RDONLY);
	line = get_next_line(fd);
	line2 = get_next_line(fd2);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
		printf("%s", line2);
		line2 = get_next_line(fd2);
	}
	close(fd);
	close(fd2);
}
