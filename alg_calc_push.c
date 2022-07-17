/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_calc_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:47:04 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/17 22:26:35 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_calc_push_a(t_list *stack_a, t_list *stack_b, int argc)
{
	int		*calc;

	calc = malloc(1 * sizeof(int));
	*calc = 0;
	if (!stack_b)
		return (NULL);
	*calc += argc - ft_delta(stack_b->rank, stack_a->rank);
	return (calc);
}

int	*ft_calc_push_b(t_list *stack_a, t_list *stack_b, int argc)
{
	int		*calc;

	calc = malloc(1 * sizeof(int));
	*calc = 0;
	if (!stack_a)
		return (NULL);
	calc += ft_delta(stack_a->rank, stack_a->next->rank);
	calc += ft_delta(stack_a->rank, ft_lstlast(stack_a)->rank);
	return (calc);
}