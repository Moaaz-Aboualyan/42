/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:16:18 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/28 14:03:44 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c);
static int	word_index(char const *str, char c, int index);
static int	word_length(char const *str, char c, int index);

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**strs;

	strs = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (strs == 0)
		return (0);
	i = 0;
	while (i < count_words(s, c))
	{
		strs[i] = ft_substr(s, word_index(s, c, i), word_length(s, c, i));
		if (strs[i] == 0)
		{
			i--;
			while (i >= 0)
			{
				free(strs[i]);
				i--;
			}
			free(strs);
			return (0);
		}
		i++;
	}
	strs[i] = 0;
	return (strs);
}

static int	word_length(char const *str, char c, int index)
{
	int	i;
	int	count;
	int	length;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (str[i] != c)
		{
			if (i == 0 || str[i - 1] == c)
			{
				count++;
				length = 0;
			}
			length++;
		}
		else if (count - 1 == index)
			return (length);
		i++;
	}
	return (length);
}

static int	word_index(char const *str, char c, int index)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (str[i] != c)
		{
			if (i == 0 || str[i - 1] == c)
			{
				if (count == index)
					return (i);
				count++;
			}
		}
		i++;
	}
	return (-1);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (str[i] != c)
		{
			if (i == 0 || str[i - 1] == c)
				count++;
		}
		i++;
	}
	return (count);
}
