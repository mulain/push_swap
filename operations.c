/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:11:04 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/14 13:15:34 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list_a, t_list **list_b, char selector)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	if (selector == 'a')
		node1 = *list_a;
	if (selector == 'b')
		node1 = *list_b;
	if (selector == 'x')
	{
		ft_swap(list_a, list_b, 'a');
		ft_swap(list_a, list_b, 'b');
	}
	node2 = node1->next;
	node3 = node2->next;
	node2->next = node1;
	node1->next = node3;
	*list_a = node2;
	// printf("node1:%i\n", *(int *)node1->content);
	// printf("node2:%i\n", *(int *)node2->content);
	// printf("node3:%i\n", *(int *)node3->content);
}