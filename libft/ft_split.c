/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:16:18 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/26 13:18:16 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	char_in_set(char c, char *charset);
static int	count_words(char *str, char *charset);
static int	word_index(char *str, char *charset, int index);
static int	word_length(char *str, char *charset, int index);

char	**ft_split(char *s, char *c)
{
	int		i;
	int		j;
	char	**strs;

	strs = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (strs == 0)
		return (0);
	i = 0;
	while (i < count_words(s, c))
	{
		j = 0;
		strs[i] = malloc((word_length(s, c, i) + 1) * sizeof(char));
		if (strs[i] == 0)
			return (0);
		while (j < word_length(s, c, i))
		{
			strs[i][j] = s[(word_index(s, c, i) + j)];
			j++;
		}
		strs[i][j] = 0;
		i++;
	}
	strs[i] = 0;
	return (strs);
}

static int	char_in_set(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	word_length(char *str, char *charset, int index)
{
	int	i;
	int	count;
	int	length;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (!(char_in_set(str[i], charset)))
		{
			if (i == 0 || char_in_set(str[i - 1], charset))
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

static int	word_index(char *str, char *charset, int index)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (!(char_in_set(str[i], charset)))
		{
			if (i == 0 || char_in_set(str[i - 1], charset))
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

static int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (!(char_in_set(str[i], charset)))
		{
			if (i == 0 || char_in_set(str[i - 1], charset))
				count++;
		}
		i++;
	}
	return (count);
}
