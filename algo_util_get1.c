/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util_get1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:23:48 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/21 22:22:35 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Return the first node that isn't in correct order.
Usually, this returns a node that is not followed by a node with higher rank.
But: If the node has the highest rank, it must be followed by the lowest rank to
not be selected.
Returns NULL if stack is ordered (regardless of stack being complete!).
*/
t_list	*ft_getnextunordered(t_list **stack)
{
	t_list	*temp;
	t_list	*highnode;
	t_list	*lownode;

	temp = *stack;
	highnode = ft_gethighrank(stack);
	lownode = ft_getlowrank(stack);
	/* printf("highnode in getnextunordered:%i\n", highnode->rank);
	printf("lownode in getnextunordered:%i\n", lownode->rank); */
	while (temp->next)
	{
		if (temp == highnode)
		{
			if (temp->next != lownode)
				return (temp);
		}
		else if (temp->rank > temp->next->rank)
			return (temp);
		temp = temp->next;
	}
	if (temp == highnode)
	{
		if (*stack != lownode)
			return (temp);
	}
	else if (temp->rank > (*stack)->rank)
		return (temp);
	//write(1, "getnextunord fool!\n", 19);
	return (NULL);
}

/* int	ft_getrankdelta(int i, int j)
{
	i -= j;
	if (i < 0)
		return (i * -1);
	return (i);
} */