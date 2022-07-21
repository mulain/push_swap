/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:03:52 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/21 08:18:48 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function would malfunction if the list is completely sorted, because it 
will always at least return the last node.
That is tested before this function is called in this program.
Counter starts at 1 because while loop terminates upon reaching the
node before the target node, so counter would be 1 too low.
*/
void	ft_setnextunordered(t_list **stack, int argc)
{
	t_list	*temp;
	int		movetonext;
	int		rotate;

	temp = *stack;
	movetonext = 0;
	while (temp->next && (temp->rank < temp->next->rank
			|| (temp->rank == argc - 1 && temp->next->rank == 1)))
	{
			temp = temp->next;
			movetonext = 1;
	}
	if (temp->next && movetonext)
		temp = temp->next;
	//printf("temprankintorotate:%i\n", temp->rank);
	rotate = ft_getrotatedir(stack, temp->rank);
	printf("rotate:%i\n", rotate);
	if (rotate == 1)
	{
		while ((*stack)->rank != temp->rank)
			ft_do_rotate_a(stack);
	}
	else if (rotate == 2)
	{
		while ((*stack)->rank != temp->rank)
			ft_do_revrotate_a(stack);
	}
}
