/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:11:26 by maboualy          #+#    #+#             */
/*   Updated: 2025/08/15 17:00:48 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s);
int	parse(const char *format, int *i, va_list args);
int	parsemore(const char *format, int *i, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	va_start(args, format);
	i = 0;
	length = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			length += parse(format, &i, args);
		else
		{
			write(1, &format[i], 1);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}

int	parse(const char *format, int *i, va_list args)
{
	int		length;
	char	c;
	void	*ptr;

	(*i)++;
	length = 0;
	if (format[*i] == 'c')
	{
		c = va_arg(args, int);
		length += write(1, &c, 1);
	}
	else if (format[*i] == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			length += write(1, &"(nil)", 5);
		else
		{
			length += write(1, &"0x", 2);
			ft_putnbr_base((unsigned long)ptr, "0123456789abcdef", &length);
		}
	}
	length += parsemore(format, i, args);
	return (length);
}

int	parsemore(const char *format, int *i, va_list args)
{
	int	length;

	length = 0;
	if (format[*i] == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (format[*i] == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", &length);
	else if (format[*i] == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", &length);
	else if (format[*i] == 'd' || format[*i] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, &length);
	else if (format[*i] == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1, &length);
	else if (format[*i] == '%')
		length += write(1, &"%", 1);
	return (length);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, &"(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
