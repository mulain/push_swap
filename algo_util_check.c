/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:50:54 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/20 13:04:55 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkifordered(t_list **stack, int argc)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->rank == argc - 1)
		{
			if (temp->next->rank != 1)
				return (0);
		}
		else if (temp->rank > temp->next->rank)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_checkifdone(t_list **stack_a, t_list **stack_b, int argc)
{
	if (!ft_checkifordered(stack_a, argc) || (*stack_a)->rank != 1 || *stack_b)
		return (0);
	return (1);
}

/* int	ft_checkifcomplete(t_list **stack)
{
	
} */