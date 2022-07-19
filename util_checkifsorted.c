/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_checkifsorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:50:54 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/19 18:16:39 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkifsorted(t_list **stack, int argc)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->rank == argc - 1)
		{
			if (temp->next->rank != 1)
				return (0);
		}
		else if (temp->rank != temp->next->rank - 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}