/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_assignrank.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:32:52 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/17 14:15:30 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Finds and returns the first node in a stack whose rank has not yet
been modified. This corresponds to rank = -1, because rank is
initialized to -1 in ft_lst_new.
*/
t_list	*ft_getfirstunranked(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (temp->rank == -1)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

/*
Assigns ranks based on the ascending values of node content.
General structure:
	-	Assign i as rank to the first unranked node
	-	Save that node as currently ranked node in currentranked
	-	Compare node content to node content of the list
		-	If node content is larger than encountered node content
			-	Assign i to the rank of encountered node and reset rank
				of currentranked node and assign currentranked to the
				encountered node
Instead of the following, i = 1 and argc - 1 is used (personal preference).
The explanation for argc - 2 is kept because it explains the approach.
It's just that instead of i = 0 and argc - 2, here i = 1 and argc - 1 is used.
The first while loop uses i and argc - 2. Usually, argc - 1 would
be used, because argc is still the initial argc including the 1 position
for the program name. We have to decrement argc here again, because
the if clause in the second while loop never modifies the last ranked node
as it requires a higher node content do so. The last ranked node has the
highest content and thus can never be modified by this if.
The last node can be reached by ft_getfirstunranked because it is the last
remaining unranked node.
*/
void	ft_assignrank(t_list **stack, int argc)
{
	int		i;
	t_list	*temp;
	t_list	*currentranked;

	i = 1;
	while (i < argc - 1)
	{
		currentranked = ft_getfirstunranked(stack);
		currentranked->rank = i;
		temp = currentranked->next;
		while (temp)
		{
			if (temp->rank == -1 && currentranked->content > temp->content)
			{
				temp->rank = i;
				currentranked->rank = -1;
				currentranked = temp;
			}
			temp = temp->next;
		}
	i++;
	}
	ft_getfirstunranked(stack)->rank = i;
}