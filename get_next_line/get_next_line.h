/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:29:24 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/13 20:30:58 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct fd_node
{
	int				fd;
	char			*buffer;
	struct fd_node	*next;
}	t_fd_node;
char	*get_next_line(int fd);
int		find_new_line(char **buffer, int fd, t_fd_node **fd_list);
ssize_t	read_next(char **buffer, int fd);
char	**get_buffer(int fd, t_fd_node **fd_list);
void	remove_fd_node(int fd, t_fd_node **fd_list);
int		ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s);

#endif
