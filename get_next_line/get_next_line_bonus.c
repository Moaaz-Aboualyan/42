/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:28:20 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/13 19:44:01 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_fd_node	*fd_list;
	char				**buffer;
	char				*line;
	char				*tmp;
	int					new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_buffer(fd, &fd_list);
	if (!(*buffer))
		return (NULL);
	if (!find_new_line(buffer, fd, &fd_list))
		return (NULL);
	new_line = ft_strchr(*buffer, '\n');
	if (new_line == -1)
		new_line = ft_strlen(*buffer);
	line = ft_substr(*buffer, 0, new_line + 1);
	tmp = *buffer;
	*buffer = ft_substr(*buffer, new_line + 1, ft_strlen(*buffer) - new_line);
	free(tmp);
	return (line);
}

int	find_new_line(char **buffer, int fd, t_fd_node **fd_list)
{
	ssize_t	bytes_read;
	int		new_line;

	new_line = ft_strchr(*buffer, '\n');
	while (new_line == -1)
	{
		bytes_read = read_next(buffer, fd);
		if (bytes_read == -1)
		{
			remove_fd_node(fd, fd_list);
			return (0);
		}
		if (bytes_read == 0)
			break ;
		new_line = ft_strchr(*buffer, '\n');
	}
	if (!(*buffer) || (!bytes_read && (*buffer)[0] == '\0'))
	{
		remove_fd_node(fd, fd_list);
		return (0);
	}
	return (1);
}

ssize_t	read_next(char **buffer, int fd)
{
	char	*tmp;
	ssize_t	bytes_read;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (-1);
	bytes_read = read(fd, tmp, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(tmp);
		return (bytes_read);
	}
	tmp[bytes_read] = '\0';
	*buffer = ft_strjoin(*buffer, tmp);
	free(tmp);
	return (bytes_read);
}

char	**get_buffer(int fd, t_fd_node **fd_list)
{
	t_fd_node	*temp;
	t_fd_node	*new;

	temp = *fd_list;
	while (temp && temp->fd != fd)
		temp = temp->next;
	if (!temp)
	{
		new = malloc(sizeof(t_fd_node));
		if (!new)
			return (NULL);
		new->fd = fd;
		new->buffer = malloc(1 * sizeof(char));
		if (!(new->buffer))
			return (NULL);
		new->buffer[0] = '\0';
		new->next = *fd_list;
		*fd_list = new;
		return (&new->buffer);
	}
	else
		return (&temp->buffer);
}

void	remove_fd_node(int fd, t_fd_node **fd_list)
{
	t_fd_node	*curr;
	t_fd_node	*prev;

	curr = *fd_list;
	prev = NULL;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				*fd_list = curr->next;
			free(curr->buffer);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
