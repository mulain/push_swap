/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:03:52 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/21 22:22:26 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Sets the next unordered node to the top of the stack.
*/
void	ft_setnextunordered(t_list **stack)
{
	t_list	*temp;
	int		rotate;

	//insert a checker into nextunordered to see if b can be
	//pushed while setting next unordered?
	//also: it only rotates once in the direction of the found node
	//shouldnt be a problem but is not very clean, erros may occur in between 
	//while runs in main algo?
	temp = ft_getnextunordered(stack);
	if (!temp)
		return ;
	//printf("getnextunordered (in setnextunordered):%i\n", temp->rank);
	rotate = ft_getrotatedir(stack, temp->rank);
	if (rotate == 1)
	{
		while ((*stack)->rank != temp->rank)
			ft_do_rotate_a(stack);
	}
	else if (rotate == 2)
	{
		while ((*stack)->rank != temp->rank)
			ft_do_revrotate_a(stack);
	}
}
