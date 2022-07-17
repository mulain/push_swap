/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_calc_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:59:55 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/17 23:23:28 by wmardin          ###   ########.fr       */
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

t_calc	*ft_calculatepoints(t_list *stack_a, t_list *stack_b, int argc)
{
	t_calc	*points;

	points = malloc(1 * sizeof(t_calc));
	argc--;
	points->push_a = ft_calc_push_a(stack_a, stack_b, argc);
	points->push_b = ft_calc_push_b(stack_a, stack_b, argc);
	points->rotate_a = ft_calc_rotate_a(stack_a, stack_b, argc);
	points->rotate_b = ft_calc_rotate_b(stack_a, stack_b, argc);
	points->revrotate_a = ft_calc_revrotate_a(stack_a, stack_b, argc);
	points->revrotate_b = ft_calc_revrotate_b(stack_a, stack_b, argc);
	points->swap_a = ft_calc_swap_a(stack_a, stack_b, argc);
	points->swap_b = ft_calc_swap_b(stack_a, stack_b, argc);
	return (points);
}