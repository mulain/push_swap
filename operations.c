/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:11:04 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/13 14:42:42 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **list_a)
{
	t_list	*temp1;
	t_list	*temp2;
	t_list	*temp3;
	
	temp1 = list_a;
	temp2 = temp1->next;
	temp3 = temp2->next;
	
	list_a->next = list_a->next->next;
	temp = list_a;
	list_a = list_a->next;
	
	list_a->next = list_a->next->next;
	list_a->next = temp;
}