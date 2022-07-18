/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:04:38 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/18 19:29:11 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp;
	t_list	*pointlist;

	if (argc < 3)
		return (0);
	stack_a = ft_makestack_a(argc, argv);
	if (!stack_a)
		return (write(2, "Error\n", 6));
	stack_b = NULL;
	ft_assignrank(&stack_a, argc);
	ft_makeslices(&stack_a, &stack_b, argc);
	ft_pushback(&stack_a, &stack_b);
	//while (!ft_checkifsorted(&stack_a))
	//pointlist = ft_calculatepoints(stack_a, stack_b, argc);
	temp = stack_a;
	printf("\nStack A:\n");
	printf("________\n");
	while (temp)
	{
		printf("rank: %i\n", temp->rank);
		temp = temp->next;
	}
	temp = stack_b;
	printf("\nStack B:\n");
	printf("________\n");
	while (temp)
	{
		printf("rank: %i\n", temp->rank);
		temp = temp->next;
	}
	//temp = pointlist;
	// while (temp)
	// {
	// 	if (temp->content == 1)
	// 	{
	// 		printf("Score push_a:%p\n", temp->score);
	// 	}
	// 	if (temp->content == 2)
	// 	{
	// 		printf("Score push_b:%i\n", *temp->score);
	// 	}
	// 	temp = temp->next;
	// }
}
