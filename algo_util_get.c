/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:05:20 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/21 08:57:54 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getrankdelta(int i, int j)
{
	i -= j;
	if (i < 0)
		return (i * -1);
	return (i);
}

/*
0 -> don't rotate
1 -> rotate
2 -> revrotate
*/
int	ft_getrotatedir(t_list **stack, int noderank)
{
	t_list	*temp;
	int		rotate;

	rotate = 0;
	temp = *stack;
	if ((*stack)->rank == noderank)
		return (0);
	while (temp->rank != noderank)
	{
		rotate++;
		temp = temp->next;
	}
	if (rotate <= ft_lstsize(*stack) - rotate)
		return (1);
	return (2);
}

int	ft_getinsertionrank(t_list **stack, int noderank, int argc)
{
	t_list	*temp;
	t_list	*currentsave;

	temp = *stack;
	while (temp->rank < noderank)
		temp = temp->next;
	currentsave = temp;
	while (temp)
	{
		if (temp->rank < noderank && temp->rank > currentsave->rank)
			currentsave = temp;
		temp = temp->next;
	}
	return (currentsave->rank);
}

/*
0 -> don't swap
1 -> swap A
2 -> swap AB
*/
int	ft_getswappable(t_list **stack_a, t_list **stack_b, int argc)
{
	if ((*stack_a)->rank == (*stack_a)->next->rank + 1
		|| ((*stack_a)->rank == 1 && (*stack_a)->next->rank == argc - 1))
	{
		if (*stack_b && (*stack_b)->next)
		{
			if ((*stack_b)->rank < (*stack_b)->next->rank)
				return (2);
		}
		else
			return (1);
	}
	return (0);
}
