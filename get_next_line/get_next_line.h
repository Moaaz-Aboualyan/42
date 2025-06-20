/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:29:24 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/14 15:12:18 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		find_new_line(int fd, char **leftover);
char	*ft_strdup(const char *s);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
