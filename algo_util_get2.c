/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util_get2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:10:34 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/22 21:12:10 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getnodeposition(t_list *node, t_list **stack)
{
	t_list	*temp;
	int		counter;

	counter = 0;
	temp = *stack;
	while (temp != node)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}
