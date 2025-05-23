/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:35:06 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/23 18:35:08 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	size_t			i;

	dst = (unsigned char *) dest;
	if (dest < src)
	{
		i = 0;
		while (n > 0)
		{
			*(dst + i) = *((unsigned char *) src + i);
			i++;
			n--;
		}
		return (dest);
	}
	i = 1;
	while (i <= n)
	{
		*(dst + n - i) = *((unsigned char *) src + n - i);
		i++;
	}
	return (dest);
}
