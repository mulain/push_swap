/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:05:20 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/21 21:27:21 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
Returns the rank of the node that should be at the top of
stack_a so the node at the top of stack_b will be in the
correct order in stack_a after having been moved there.
Usually, this returns the node with the next highest rank.
If stack_b has higher rank than all nodes in stack_a, the lowest
ranked node of stack_a is returned.
*/
int	ft_getinsertionrank(t_list **stack, int noderank)
{
	t_list	*temp;
	t_list	*save;
	t_list	*highnode;
	t_list	*lownode;

	temp = *stack;
	highnode = ft_gethighrank(stack);
	lownode = ft_getlowrank(stack);
	if (noderank > highnode->rank)
		return (lownode->rank);
	if (noderank < lownode->rank)
		return (highnode->rank);
	while (noderank > temp->rank)
		temp = temp->next;
	save = temp;
	while (temp)
	{
		if (noderank > temp->rank && temp->rank > save->rank)
			save = temp;
		temp = temp->next;
	}
	return (save->rank);
}

/*
0 -> don't swap
1 -> swap A
2 -> swap AB
*/
int	ft_getswappable(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*highnode;
	t_list	*lownode;

	highnode = ft_gethighrank(stack_a);
	lownode = ft_getlowrank(stack_a);
	if ((*stack_a)->rank == (*stack_a)->next->rank + 1
		|| (*stack_a == lownode && (*stack_a)->next == highnode))
	{
		if (*stack_b && (*stack_b)->next)
		{
			if ((*stack_b)->rank < (*stack_b)->next->rank
				|| ((*stack_b)->rank == argc - 1
					&& (*stack_b)->next->rank == 1))
				return (2);
		}
		else
			return (1);
	}
	return (0);
}

/*
Returns the node with the highest rank in the stack.
*/
t_list	*ft_gethighrank(t_list **stack)
{
	t_list	*temp;
	t_list	*save;

	temp = *stack;
	save = temp;
	while (temp)
	{
		if (temp->rank > save->rank)
			save = temp;
		temp = temp->next;
	}
	return (save);
}

/*
Returns the node with the lowest rank in the stack.
*/
t_list	*ft_getlowrank(t_list **stack)
{
	t_list	*temp;
	t_list	*save;

	temp = *stack;
	save = temp;
	while (temp)
	{
		if (temp->rank < save->rank)
			save = temp;
		temp = temp->next;
	}
	return (save);
}