/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:03:47 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/24 11:30:15 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*found;
	int		i;

	i = 0;
	found = 0;
	while (s[i])
	{
		if (s[i] == c)
			found = (char *)(s + i);
		i++;
	}
	if (found)
		return (found);
	if (s[i] == c)
		return ((char *)(s + i));
	return (0);
}
