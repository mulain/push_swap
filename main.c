/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:04:38 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/21 21:21:18 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 3)
		return (0);
	stack_a = ft_makestack_a(argc, argv);
	if (!stack_a)
		return (write(2, "Error\n", 6));
	stack_b = NULL;
	if (ft_checkifdone(&stack_a, &stack_b))
	{
		ft_free_stack(&stack_a);
		//return (write(1, "\n", 1));
		return(0) ;
	}
	ft_algo_main(&stack_a, &stack_b, argc);
	ft_finalrotation(&stack_a);
	ft_free_stack(&stack_a);
}
