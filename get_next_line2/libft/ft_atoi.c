/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:32:08 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/28 14:03:02 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(int c);

int	ft_atoi(const char *nptr)
{
	int		negative;
	int		i;
	int		n;
	char	*s;

	s = (char *) nptr;
	i = 0;
	while (ft_iswhitespace(s[i]))
		i++;
	negative = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			negative = 1;
		i++;
	}
	n = 0;
	while (ft_isdigit(s[i]))
	{
		n = (n * 10) + (s[i] - '0');
		i++;
	}
	if (negative)
		n = -n;
	return (n);
}

static int	ft_iswhitespace(int c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r');
}
