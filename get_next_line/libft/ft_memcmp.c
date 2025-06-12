/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:32:18 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/02 10:25:08 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	while (n)
	{
		str1 = (unsigned char *)(s1 + i);
		str2 = (unsigned char *)(s2 + i);
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		i++;
		n--;
	}
	return (0);
}
