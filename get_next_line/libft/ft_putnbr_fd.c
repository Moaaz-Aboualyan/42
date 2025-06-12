/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:22:27 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/02 09:41:27 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	number;

	if (n < 0)
	{
		write(fd, &"-", 1);
		if (n == -2147483648)
			write(fd, &"2147483648", 10);
		else
			n = -n;
	}
	if (n >= 0 && n < 10)
	{
		number = n + '0';
		write(fd, &number, 1);
	}
	else if (n > 0)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
