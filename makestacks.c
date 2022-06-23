/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:16:52 by wmardin           #+#    #+#             */
/*   Updated: 2022/06/23 22:16:49 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_makestack_a(int *ints, int argc)
{
	int     i;
    t_list  *stack_a;
    
    i = 0;
    stack_a = NULL;
    while (i < argc - 1)
    {
        ft_lstadd_back(&stack_a, ft_lstnew(ints + i));
        i++;
    }
    return (stack_a);
}