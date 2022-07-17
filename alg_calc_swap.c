/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_calc_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:24:45 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/17 23:54:33 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_calc_swap_a(t_list *stack_a, t_list *stack_b, int argc)
{
	int	*calc;

	calc = malloc(1 * sizeof(int *));
	calc = NULL;
	if (!stack_a)
		return (NULL);
	if (stack_a->rank == stack_a->next->rank + 1)
		calc = NULL;
	return (NULL);
}

int	*ft_calc_swap_b(t_list *stack_a, t_list *stack_b, int argc)
{
	int	*calc;
	int	score;

	calc = malloc(1 * sizeof(int *));
	score = 0;
	if (!stack_b)
		return (NULL);
	if (stack_b->rank == stack_a->next->rank - 1)
		score = 2147483647;
	return (calc = &score);
}
