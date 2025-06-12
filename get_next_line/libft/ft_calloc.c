/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:10:05 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/02 10:40:55 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (size != 0 && nmemb != ((nmemb * size) / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
		ptr[i++] = 0;
	return (ptr);
}
