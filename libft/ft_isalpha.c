/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <maboualy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:00:28 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/19 15:12:11 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int c)
{
  if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
  {
    return (1024);
  }
  return (0);
}

int main(void) {
  printf("mine: %d\n", ft_isalpha('A'));
  printf("real: %d\n", isalpha('A'));
}
