/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_slices.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:21 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/19 18:43:55 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_makeslices(t_list **stack_a, t_list **stack_b, int argc)
{
	int		counter;
	t_list	*temp;

	counter = 0;
	while (counter < argc - 3 && !ft_checkifsorted(stack_a, argc))
	{
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
}

void	ft_pushback(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		counter;

	counter = 0;
	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_b && counter < 100)
	{
		if (temp_b->rank < temp_a->rank && temp_b->rank > ft_lstlast(temp_a)->rank)
			ft_do_push_a(stack_a, stack_b);
		else
			ft_do_rotate_a(stack_a);
		// else if (ft_delta(temp_b->rank, temp_a->rank) > ft_delta(temp_b->rank, ft_lstlast(temp_a)->rank))
		// 	ft_do_revrotate_b(stack_b);
		// else
		// 	ft_do_rotate_b(stack_b);
		temp_a = *stack_a;
		temp_b = *stack_b;
		counter++;
	}
	printf("counter: %i\n", counter);
}

void	ft_finalrotation(t_list **stack, int argc)
{
	t_list	*temp;
	int		rotate;

	rotate = 0;
	while (temp->rank != 1)
	{
		rotate++;
		temp = temp->next;
	}
	if (rotate <= (argc - 1) / 2)
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
