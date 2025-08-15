/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:18:27 by maboualy          #+#    #+#             */
/*   Updated: 2025/08/15 16:39:04 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

void	ft_putnbr_base(long nbr, char *base, int *length);
void	ft_putnbr_fd(long n, int fd, int *length);
int		ft_printf(const char *format, ...);

#endif 
