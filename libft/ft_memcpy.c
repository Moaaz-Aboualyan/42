/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:35:51 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/28 14:00:29 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	size_t			i;

	dst = (unsigned char *) dest;
	i = 0;
	while (n > 0)
	{
		*(dst + i) = *((unsigned char *) src + i);
		i++;
		n--;
	}
	return (dest);
}
