/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:37:01 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/24 10:41:10 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
	while (src[i] != 0)
	{
		length++;
	}
	return (length);
}
