/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_slices.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:21 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/20 13:22:57 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_makeslices(t_list **stack_a, t_list **stack_b, int argc)
{
	int		counter;
	t_list	*temp;

	counter = 0;
	while (counter < argc - 3)
	{
		if (ft_checkifordered(stack_a, argc))
			return (ft_pushback(stack_a, stack_b));
		temp = *stack_a;
		if (temp->rank != 1 && temp->rank != argc - 1)
		{
			if (temp->rank == temp->next->rank + 1) //maybe work with delta?
				ft_do_swap_a(stack_a);
			else
				ft_do_push_b(stack_a, stack_b); //identify node to swap. either node not in order (or surpassing an acceptable delta), or maybe detect a node cluster?
			counter++;
		}
		else
			ft_do_rotate_a(stack_a);
	}
	ft_pushback(stack_a, stack_b);
}

void	ft_pushback(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		if ((*stack_b)->rank < (*stack_a)->rank
			&& (*stack_b)->rank > ft_lstlast(*stack_a)->rank)
			ft_do_push_a(stack_a, stack_b);
		else
		{
			if (ft_getrotatedir(stack_a,
					ft_getinsertionrank(stack_a, (*stack_b)->rank)) == 1)
				ft_do_rotate_a(stack_a);
			else
				ft_do_revrotate_a(stack_a);
		// else if (ft_delta(temp_b->rank, temp_a->rank) > ft_delta(temp_b->rank, ft_lstlast(temp_a)->rank))
		// 	ft_do_revrotate_b(stack_b);
		// else
		// 	ft_do_rotate_b(stack_b);
		}
	}
}

void	ft_finalrotation(t_list **stack)
{
	if (ft_getrotatedir(stack, 1) == 1)
	{
		while ((*stack)->rank != 1)
			ft_do_rotate_a(stack);
	}
	else
	{
		while ((*stack)->rank != 1)
			ft_do_revrotate_a(stack);
	}
}
