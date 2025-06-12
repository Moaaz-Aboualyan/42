/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:03:47 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/02 08:03:41 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cchar;

	i = 0;
	cchar = c;
	while (s[i])
	{
		if (s[i] == cchar)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == cchar)
		return ((char *)(s + i));
	return (0);
}
