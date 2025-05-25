/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:54:28 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/24 16:10:44 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_substr.c"

int	charinstr(int c, const char *s);

char *ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	while(charinstr(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (charinstr(s1[end], set))
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}

int	charinstr(int c, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
