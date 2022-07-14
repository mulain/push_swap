/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:04:38 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/14 21:17:58 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*ints;
	t_list	*temp;

	if (argc < 3)
		return (0);
	ints = ft_errorcheck(argc, argv);
	if (!ints)
		return (write(2, "Error\n", 6));
	stack_a = ft_makestack_a(ints, argc);
	stack_b = NULL;

	temp = stack_a;
	//ft_do_swap_a(&stack_a);
	/* ft_do_push_b(&stack_a, &stack_b);
	ft_do_push_b(&stack_a, &stack_b);
	ft_do_push_b(&stack_a, &stack_b);
	ft_do_push_b(&stack_a, &stack_b); */
	ft_do_rotate_a(&stack_a);
	temp = stack_a;
	printf("Stack A:\n");
	while (temp)
	{
		printf("%i\n", *(int *)temp->content);
		temp = temp->next;
	}
	temp = stack_b;
	printf("Stack B:\n");
	while (temp)
	{
		printf("%i\n", *(int *)temp->content);
		temp = temp->next;
	}
	// printf("list_a:%i\n", *(int *)stack_a->content);
}
