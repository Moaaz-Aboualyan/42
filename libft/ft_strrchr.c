/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:03:47 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/28 14:28:59 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*found;
	int		i;
	char	cchar;

	i = 0;
	found = 0;
	cchar = c;
	while (s[i])
	{
		if (s[i] == cchar)
			found = (char *)(s + i);
		i++;
	}
	if (found)
		return (found);
	if (s[i] == cchar)
		return ((char *)(s + i));
	return (0);
}
