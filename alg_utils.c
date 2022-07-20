/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:05:20 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/20 12:03:39 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_delta(int i, int j)
{
	i -= j;
	if (i < 0)
		return (i * -1);
	return (i);
}

/*
1 -> rotate
2 -> revrotate
*/
int	ft_rotatedirection(t_list **stack, int noderank)
{
	t_list	*temp;
	int		rotate;

	rotate = 0;
	temp = *stack;

	while (temp->rank != noderank)
	{
		rotate++;
		temp = temp->next;
	}
	if (rotate <= ft_lstsize(*stack) / 2)
		return (1);
	return (2);
}

int	ft_getinsertionrank(t_list **stack, int noderank)
{
	t_list	*temp;
	t_list	*currentsave;

	temp = *stack;
	while (temp->rank > noderank)
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
