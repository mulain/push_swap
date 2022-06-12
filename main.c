/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:56:59 by wmardin           #+#    #+#             */
/*   Updated: 2022/06/12 19:10:15 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	**lst;

	i = 1;
	while (i < argc)
	{
		if (ft_isnumberformat(argv[i]) == 0)
			return (write (2, "Error\n", 6));
	}
	i = 1;
	lst = NULL;
	while (i < argc)
	{
		ft_lstadd_back(lst, ft_lstnew(argv[i]));
		ft_strlen(argv[i]);
		printf("test4\n");
		i++;
	}
	printf("%p knudel\n", lst);
	printf("Hello6\n");
	/* while (temp->next)
	{
		printf("%i\n", temp->content);
		temp = temp->next;
	} */
}