/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:21 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/21 08:54:42 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_makeslices(t_list **stack_a, t_list **stack_b, int argc)
{
	int		swap;

	while (!ft_checkifordered(stack_a, argc))
	{
		swap = ft_getswappable(stack_a, stack_b, argc);
		if (swap == 1)
			ft_do_swap_a(stack_a);
		if (swap == 2)
			ft_do_swap_ab(stack_a, stack_b);
		if (swap == 0)
		{
			ft_setnextunordered(stack_a, argc);
			//insert a checker into nextunordered to see if b can be
			//pushed while setting next unordered?
			ft_do_push_b(stack_a, stack_b);
		}
	}
	ft_pushback(stack_a, stack_b);
}

void	ft_pushback(t_list **stack_a, t_list **stack_b)
{
/* 	t_list	*temp;
 */	
	while (*stack_b)
	{
		if ((*stack_b)->rank < (*stack_a)->rank
			&& (*stack_b)->rank > ft_lstlast(*stack_a)->rank)
			ft_do_push_a(stack_a, stack_b);
		else
		{
			//printsection____________________________________
			/* temp = *stack_a;
			printf("\nStack A:\n");
			printf("________\n");
			while (temp)
			{
				printf("rank: %i\n", temp->rank);
				temp = temp->next;
			}
			temp = *stack_b;
			printf("\nStack B:\n");
			printf("________\n");
			while (temp)
			{
				printf("rank: %i\n", temp->rank);
				temp = temp->next;
			} */
			//printsection____________________________________

			if (ft_getrotatedir(stack_a,
					ft_getinsertionrank(stack_a, (*stack_b)->rank)) == 1)
				ft_do_rotate_a(stack_a);
			else
				ft_do_revrotate_a(stack_a);
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
	else if (ft_getrotatedir(stack, 1) == 2)
	{
		while ((*stack)->rank != 1)
			ft_do_revrotate_a(stack);
	}
}
