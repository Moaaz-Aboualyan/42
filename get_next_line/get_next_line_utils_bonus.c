/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:29:14 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/13 19:37:09 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	cchar;

	i = 0;
	cchar = c;
	while (s[i])
	{
		if (s[i] == cchar)
			return (i);
		i++;
	}
	if (s[i] == cchar)
		return (i);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > (ft_strlen(s) - start))
		s2 = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		s2 = malloc(len + 1);
	if (!s2)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (0);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = 0;
	free(s1);
	return (s3);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;

	s2 = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!s2)
		return (0);
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
