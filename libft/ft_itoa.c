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

static int	intasstrlen(long n);

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		strlen;
	long	nbr;

	strlen = intasstrlen(nbr);
	str = malloc(strlen * sizeof(char));
	nbr = n;
	if (!str)
		return (0);
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	i = 1;
	while (nbr > 0)
	{
		str[strlen - i] = ((nbr % 10) + '0');
		i++;
		nbr /= 10;
	}
	str[strlen] = 0;
	return (str);
}

static int	intasstrlen(long n)
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
