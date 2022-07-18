/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:04:38 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/18 10:29:58 by wmardin          ###   ########.fr       */
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
	//while (!ft_checkifsorted(&stack_a))
	pointlist = ft_calculatepoints(stack_a, stack_b, argc);
	temp = stack_a;
	printf("Stack A:\n");
	while (temp)
	{
		printf("content: %i; ", temp->content);
		printf("rank: %i\n", temp->rank);
		temp = temp->next;
	}
	temp = stack_b;
	printf("Stack B:\n");
	while (temp)
	{
		printf("%i\n", temp->content);
		temp = temp->next;
	}
	temp = pointlist;
	while (temp)
	{
		if (temp->content == 1)
		{
			printf("Score push_a:%p\n", temp->score);
		}
		if (temp->content == 2)
		{
			printf("Score push_b:%i\n", *temp->score);
		}
		temp = temp->next;
	}
}
