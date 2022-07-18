/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_calc_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:59:55 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/18 10:28:06 by wmardin          ###   ########.fr       */
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

/*
Lookup table:
Number	Action
1		push_a
2		push_b
3		rotate_a
4		rotate_b
5		rotate_ab
6		revrotate_a
7		revrotate_b
8		revrotate_ab
9		swap_a
10		swap_b
11		swap_ab
*/
t_list	*ft_calculatepoints(t_list *stack_a, t_list *stack_b, int argc)
{
	t_list	*scorelist;
	t_list	*temp;
	int		i;

	scorelist = NULL;
	i = 1;
	argc--;
	while (i < 12)
	{
		ft_lstadd_back(&scorelist, ft_lstnew(i));
		i++;
	}
	temp = scorelist;
	while (temp)
	{
		printf("whilecalc\n");
		if (temp->content == 1)
		{
			temp->score = ft_calc_push_a(stack_a, stack_b, argc);
			if (temp->score)
				printf("tempscore:%p\n", *temp->score);
		}
		if (temp->content == 2)
		{
			printf("whilecalc cont 2\n");
			temp->score = ft_calc_push_b(stack_a, stack_b, argc);
		}
		if (temp->content == 3)
			temp->score = ft_calc_rotate_a(stack_a, stack_b, argc);
		if (temp->content == 4)
			temp->score = ft_calc_rotate_b(stack_a, stack_b, argc);
		if (temp->content == 5)
			temp->score = ft_calc_rotate_ab(stack_a, stack_b, argc);
		if (temp->content == 6)
			temp->score = ft_calc_revrotate_a(stack_a, stack_b, argc);
		if (temp->content == 7)
			temp->score = ft_calc_revrotate_b(stack_a, stack_b, argc);
		if (temp->content == 8)
			temp->score = ft_calc_revrotate_ab(stack_a, stack_b, argc);
		if (temp->content == 9)
			temp->score = ft_calc_swap_a(stack_a, stack_b, argc);
		if (temp->content == 10)
			temp->score = ft_calc_swap_b(stack_a, stack_b, argc);
		if (temp->content == 11)
			temp->score = ft_calc_swap_ab(stack_a, stack_b, argc);
		temp = temp->next;
	}
	return (scorelist);
}

/*
Lookup table:
Number	Action
1		push_a
2		push_b
3		rotate_a
4		rotate_b
5		rotate_ab
6		revrotate_a
7		revrotate_b
8		revrotate_ab
9		swap_a
10		swap_b
11		swap_ab
*/
/* int	selectaction(t_calc *points)
{
	int		action;
	int		*temp;

	action = 1;
	temp = points->push_a;
	if (points->push_b > temp)
		temp = points->push_b;
		action = 2;
	if (points->rotate_a > temp)
		temp = points->rotate_a;
		action = 3;
	if (points->rotate_b > temp)
		temp = points->rotate_b;
	if (points->revrotate_a > temp)
		temp = points->revrotate_a;
	if (points->revrotate_b > temp)
		temp = points->revrotate_b;
	if (points->swap_a > temp)
		temp = points->swap_a;
	if (points->swap_b > temp)
		temp = points->swap_b;
} */