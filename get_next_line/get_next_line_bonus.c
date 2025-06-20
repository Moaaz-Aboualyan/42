/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:28:20 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/14 15:54:36 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_fd_node	*leftovers;
	char				**leftover;
	char				*buffer;
	char				*line;
	int					new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = get_leftover(fd, &leftovers);
	if (!(*leftover))
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	new_line = find_new_line(fd, leftover, &leftovers, buffer);
	free(buffer);
	if (new_line == -1)
		return (NULL);
	buffer = *leftover;
	line = ft_substr(*leftover, 0, new_line + 1);
	*leftover = ft_substr(*leftover, new_line + 1,
			ft_strlen(*leftover) - new_line);
	free (buffer);
	return (line);
}

int	find_new_line(int fd, char **leftover, t_fd_node **leftovers, char *buffer)
{
	ssize_t		bytes_read;
	int			new_line;

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
	if (!(*leftover) || (*leftover)[0] == '\0')
	{
		remove_fd_node(fd, leftovers);
		return (-1);
	}
	if (new_line == -1)
		return (ft_strlen(*leftover));
	return (new_line);
}

char	**get_leftover(int fd, t_fd_node **leftovers)
{
	t_fd_node	*tmp;
	t_fd_node	*new;

	tmp = *leftovers;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		new = malloc(sizeof(t_fd_node));
		if (!new)
			return (NULL);
		new->fd = fd;
		new->buffer = malloc(sizeof(char));
		if (!(new->buffer))
		{
			free(new);
			return (NULL);
		}
		new->buffer[0] = '\0';
		new->next = *leftovers;
		*leftovers = new;
		return (&new->buffer);
	}
	else
		return (&tmp->buffer);
}

void	remove_fd_node(int fd, t_fd_node **leftovers)
{
	t_fd_node	*curr;
	t_fd_node	*prev;

	curr = *leftovers;
	prev = NULL;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				*leftovers = curr->next;
			free(curr->buffer);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
