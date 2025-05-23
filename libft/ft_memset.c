/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:35:58 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/23 18:35:59 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*dst;

	dst = (unsigned char *) ptr;
	while (n > 0)
	{
		*dst = c;
		dst++;
		n--;
	}
	return (ptr);
}
