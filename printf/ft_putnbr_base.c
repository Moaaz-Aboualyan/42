/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:39:34 by maboualy          #+#    #+#             */
/*   Updated: 2025/08/15 16:53:01 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

int	validate(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] < 33 || base[i] > 126 || base[i] == '+' || base[i] == '-')
			return (1);
		j = 1;
		while (base[i + j] != 0)
		{
			if (base[i + j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

void	ft_putnbr_base(unsigned long nbr, char *base, int *length)
{
	unsigned long	base_length;

	if (validate(base) == 1)
		return ;
	base_length = ft_strlen(base);
	if (nbr < base_length)
	{
		write(1, &base[nbr], 1);
		(*length)++;
	}
	else
	{
		ft_putnbr_base((nbr / base_length), base, length);
		ft_putnbr_base((nbr % base_length), base, length);
	}
}
