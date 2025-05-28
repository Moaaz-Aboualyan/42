/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:37:01 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/28 13:42:28 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	length;
	size_t			i;
	size_t			dstlen;

	i = 0;
	dstlen = 0;
	while (dst[i] != 0)
		i++;
	dstlen = i;
	while (src[i] != 0 && i < (size + dstlen - 1))
	{
		dst[i] = src[i];
		i++;
	}
	length = i;
	dst[i] = 0;
	while (src[length] != 0)
	{
		length++;
		i++;
	}
	return (length);
}
