/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:31:05 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/28 14:04:02 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intasstrlen(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		strlen;

	strlen = intasstrlen(n);
	str = malloc(strlen * sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	i = 1;
	while (n > 0)
	{
		str[strlen - i] = ((n % 10) + '0');
		i++;
		n /= 10;
	}
	str[strlen] = 0;
	return (str);
}

static int	intasstrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
