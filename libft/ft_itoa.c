/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:31:05 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/02 10:22:08 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(long n);
static char	*set_string(long nbr, int len);

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	int		len;
	int		i;

	nbr = n;
	len = intlen(nbr);
	str = set_string(nbr, len);
	if (!str)
		return (NULL);
	i = len - 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}

static char	*set_string(long nbr, int len)
{
	char	*str;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	return (str);
}

static int	intlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
//
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// }
