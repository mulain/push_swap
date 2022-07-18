/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_slices.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:21 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/18 20:55:59 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_makeslices(t_list **stack_a, t_list **stack_b, int argc)
{
	int		counter;
	t_list	*temp;

	counter = 0;
	argc--;
	temp = *stack_a;
	while (counter < argc - 3)
	{
		if (temp->rank != 1 /* && temp->rank != argc / 2 */ && temp->rank != argc)
		{
			ft_do_push_b(stack_a, stack_b);
			counter++;
		}
		else
			ft_do_rotate_a(stack_a);
		temp = *stack_a;
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
