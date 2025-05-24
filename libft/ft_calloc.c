/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:10:05 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/24 14:19:21 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc(n * size);
	if (!ptr)
		return (0);
	i = 0;
	while (i < (n * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
