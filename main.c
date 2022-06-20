/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:04:38 by wmardin           #+#    #+#             */
/*   Updated: 2022/06/20 21:08:17 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int		*ints;
	int		i;
	t_list	*temp;

	ints = ft_errorcheck(argc, argv);
	if (!ints)
		return (write(2, "Error\n", 6));
	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ints + i));
		i++;
	}
	temp = stack_a;
	while (temp)
	{
		printf("%i\n", *(int *)temp->content);
		temp = temp->next;
	}
}
