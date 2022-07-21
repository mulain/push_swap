/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:50:54 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/21 21:19:35 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Only checks for order in the stack, not for completion.
A list with nodes of rank 1, 3, 9 would be true.
*/
int	ft_checkifordered(t_list **stack)
{
	t_list	*temp;
	t_list	*comparenode;
	t_list	*highnode;
	t_list	*lownode;

	highnode = ft_gethighrank(stack);
	lownode = ft_getlowrank(stack);
	/* printf("highnode in ordercheck:%i\n", highnode->rank);
	printf("lownode in ordercheck:%i\n", lownode->rank); */
	temp = *stack;
	while (temp)
	{
		if (temp->next)
			comparenode = temp->next;
		else
			comparenode = *stack;
		if (temp == highnode)
		{
			if (comparenode != lownode)
				return (0);
		}
		else if (temp->rank > comparenode->rank)
			return (0);
		temp = temp->next;
	}
	/* printf("return1 from checkifordered\n"); */
	return (1);
}

int	ft_checkifdone(t_list **stack_a, t_list **stack_b)
{
	if (!ft_checkifordered(stack_a) || (*stack_a)->rank != 1 || *stack_b)
		return (0);
	return (1);
}

/* int	ft_checkifcomplete(t_list **stack)
{
	
} */