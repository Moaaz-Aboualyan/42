/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:43:34 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/28 14:41:36 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	int			found;

	i = 0;
	if (!little[i])
		return ((char *) big);
	while (big[i] && (i + ft_strlen(little) - 1) < len)
	{
		j = 0;
		found = 1;
		while (little[j])
		{
			if (big[i + j] == 0)
				return (0);
			if (big[i + j] != little[j])
				found = 0;
			j++;
		}
		if (found == 1)
			return (&(((char *)big)[i]));
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = "aaabcabcd";
// 	printf("%s\n", ft_strnstr(str, "cd", 8));
// }
