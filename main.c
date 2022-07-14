/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:04:38 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/14 13:18:27 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int		*ints;
	t_list	*temp;

	if (argc < 3)
		return (0);
	ints = ft_errorcheck(argc, argv);
	if (!ints)
		return (write(2, "Error\n", 6));
	stack_a = ft_makestack_a(ints, argc);
	
	
	temp = stack_a;
	while (temp)
	{
		printf("%i\n", *(int *)temp->content);
		temp = temp->next;
	}
	ft_swap(&stack_a, NULL, 'f');
	temp = stack_a;
	while (temp)
	{
		printf("%i\n", *(int *)temp->content);
		temp = temp->next;
	}
	// printf("list_a:%i\n", *(int *)stack_a->content);
}
