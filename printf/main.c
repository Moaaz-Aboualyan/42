/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:36:57 by maboualy          #+#    #+#             */
/*   Updated: 2025/08/15 16:38:45 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main(void)
{
	int	*number;

	number = malloc(sizeof(int));
	*number = 42;
	printf("return value: %d\n", printf(" %c ", '0'));
	printf("return value: %d\n", ft_printf(" %c ", '0'));
}
