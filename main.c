/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:04:38 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/20 12:13:02 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp;

	if (argc < 3)
		return (0);
	stack_a = ft_makestack_a(argc, argv);
	if (!stack_a)
		return (write(2, "Error\n", 6));
	stack_b = NULL;
	if (ft_checkifdone(&stack_a, argc))
	{
		ft_free_stack(&stack_a);
		return (write(1, "\n", 1));
	}
	ft_makeslices(&stack_a, &stack_b, argc);
	ft_finalrotation(&stack_a);

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
	ft_free_stack(&stack_a);
}
