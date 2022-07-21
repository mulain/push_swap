/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:21 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/21 21:29:19 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_main(t_list **stack_a, t_list **stack_b, int argc)
{
	int		swap;
	//t_list	*temp;

	while (!ft_checkifordered(stack_a))
	{
		//printf("checkifordered at start:%i\n", ft_checkifordered(stack_a));
		//printf("stack_a rank:%i\n", (*stack_a)->rank);
		swap = ft_getswappable(stack_a, stack_b, argc);
		if (swap == 1)
			ft_do_swap_a(stack_a);
		if (swap == 2)
			ft_do_swap_ab(stack_a, stack_b);
		if (swap == 0)
		{
			if (*stack_a == ft_getnextunordered(stack_a))
				ft_do_push_b(stack_a, stack_b);
			ft_setnextunordered(stack_a);
		}
			
			/* temp = *stack_a;
			printf("\nStack A after pushb:\n");
			printf("________\n");
			while (temp)
			{
				printf("rank: %i\n", temp->rank);
				temp = temp->next;
			}
			temp = *stack_b;
			printf("\nStack B after pushb:\n");
			printf("________\n");
			while (temp)
			{
				printf("rank: %i\n", temp->rank);
				temp = temp->next;
			} */
			

		
	}
	ft_pushback(stack_a, stack_b);
}

/*
This function is called when stack_a is ordered. Doesn't mean stack_a is
complete, just that its contents are completely in the correct order.
*/
void	ft_pushback(t_list **stack_a, t_list **stack_b)
{
	//t_list	*temp;
	t_list		*highnode_a;
	t_list		*lownode_a;

	while (*stack_b)
	{
		highnode_a = ft_gethighrank(stack_a);
		lownode_a = ft_getlowrank(stack_a);
		if ((*stack_b)->rank > highnode_a->rank
			&& *stack_a == lownode_a)
			ft_do_push_a(stack_a, stack_b);
		/* {
			if (*stack_a == lownode_a)
				ft_do_push_a(stack_a, stack_b);
			//Do stuff so stack a does turn into lownode a
		} */
		else if ((*stack_b)->rank < (*stack_a)->rank
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
