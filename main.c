/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:04:38 by wmardin           #+#    #+#             */
/*   Updated: 2022/06/23 19:39:16 by wmardin          ###   ########.fr       */
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

	if (argc < 3)
		return (0);
	ints = ft_errorcheck(argc, argv);
	if (!ints)
		return (write(2, "Error\n", 6));
	i = 0;
	stack_a = NULL;
	while (i < argc - 1)
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
