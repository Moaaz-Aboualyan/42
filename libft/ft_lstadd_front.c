/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:16:52 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/26 15:35:50 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
}

#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	long	num = 42;
	long	num2 = 420;
	t_list	*node;
	t_list	*node2;

	node = malloc(sizeof(t_list));
	node->content = (void *)&num;
	node->next = 0;
	node2 = malloc(sizeof(t_list));
	node2->content = (void *)&num2;
	node2->next = 0;
	ft_lstadd_front(&node, node2);
	printf("first node: %ld\n", *(long *)(node2->content));
	printf("second node: %ld\n", *(long *)((node2->next)->content));
}
