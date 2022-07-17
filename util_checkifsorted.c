/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_checkifsorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:50:54 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/17 17:54:18 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkifsorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->content != temp->next->content - 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}