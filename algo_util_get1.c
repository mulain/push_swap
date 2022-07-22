/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util_get1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:23:48 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/22 21:38:03 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getdowntrain(t_list *node, t_list **stack)
{
	t_list	*temp;
	int		counter;

	temp = *stack;
	counter = 0;
	while (temp != node)
		temp = temp->next;
	while (temp->next && temp->rank < temp->next->rank)
	{
		temp = temp->next;
		counter++;
	}
	if (temp->rank > (*stack)->rank || (temp == ft_gethighrank(stack)
			&& *stack == ft_getlowrank(stack)))
	{
		counter++;
		while (temp != node)
		{
			if (temp->rank < temp->next->rank)
			{
				temp = temp->next;
				counter++;
			}
			else
				return (counter);
		}
	}
	return (counter);
}

/*
Returns the number of nodes in correct order upwards of  the node passed
to the function.
*/
int	ft_getuptrain(t_list *node, t_list **stack)
{
	t_list	*temp;
	t_list	*lastnode;
	int		counter;

	temp = *stack;
	lastnode = ft_lstlast(*stack);
	counter = ft_getnodeposition(node, stack);
	if ((*stack)->rank > lastnode->rank || (lastnode == ft_gethighrank(stack)
			&& *stack == ft_getlowrank(stack)))
	{
		counter++;
		while (node != lastnode)
		{
			temp = *stack;
			while (temp->next != lastnode)
				temp = temp->next;
			if (temp->rank < lastnode->rank)
			{
				lastnode = temp;
				counter++;
			}
			else
				return (counter);
		}
	}
	return (counter);
}

t_list	*ft_getnextunordered(t_list **stack)
{
	t_list	*firstnode;
	t_list	*secondnode;
	int		uptrain;
	int		downtrain;

	firstnode = ft_getdiscrepancy(stack);
	printf("firstnode:%i\n", firstnode->rank);
	if (!firstnode->next)
		return (firstnode);
	secondnode = firstnode->next;
	uptrain = ft_getuptrain(firstnode, stack);
	printf("uptrain:%i\n", uptrain);
	downtrain = ft_getdowntrain(secondnode, stack);
	printf("downtrain:%i\n", downtrain);
	if (downtrain > uptrain)
		return (firstnode);
	if (uptrain > downtrain)
		return (secondnode);
	printf("getnextunordered: shouldnt reach this\n");
	return (firstnode);
}

/*
Returns the first node that isn't followed by a correct node.
Returns NULL if stack is ordered (regardless of stack being complete or not).
*/
t_list	*ft_getdiscrepancy(t_list **stack)
{
	t_list	*temp;
	t_list	*highnode;
	t_list	*lownode;

	temp = *stack;
	highnode = ft_gethighrank(stack);
	lownode = ft_getlowrank(stack);
	/* printf("highnode in getdiscrepancy:%i\n", highnode->rank);
	printf("lownode in getdiscrepancy:%i\n", lownode->rank); */
	while (temp->next)
	{
		if (temp == highnode)
		{
			//printf("get discrepancy: ifhighnode\n");
			if (temp->next != lownode)
				return (temp); //->next was removed for trainspotting. was good if not using trains
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