/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:35:25 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/23 18:35:26 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*dst;

	dst = (unsigned char *) ptr;
	while (n > 0)
	{
		*dst = (unsigned char) 0;
		dst++;
		n--;
	}
}
