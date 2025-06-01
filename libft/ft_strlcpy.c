/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:37:01 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/28 14:54:10 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != 0 && i < (size ))
	{
		dst[i] = src[i];
		i++;
	}
	return (ft_strlen(src));
}

#include <stdio.h>
#include <string.h>
int main(void)
{
	char src[] = "coucou";
	char dest[10]; memset(dest, 'A', 10);
	size_t returnvalue = strlcpy(dest, src, 0);
	printf("1 me: %s, %s, %zu ", src, dest, returnvalue);
}
