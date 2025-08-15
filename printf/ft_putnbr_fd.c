/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:22:27 by maboualy          #+#    #+#             */
/*   Updated: 2025/08/15 15:44:42 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(long n, int fd, int *length)
{
	int	number;

	if (n < 0)
	{
		write(fd, &"-", 1);
		(*length)++;
		n = -n;
	}
	if (n >= 0 && n < 10)
	{
		number = n + '0';
		write(fd, &number, 1);
		(*length)++;
	}
	else if (n > 0)
	{
		ft_putnbr_fd(n / 10, fd, length);
		ft_putnbr_fd(n % 10, fd, length);
	}
}
