/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumberformat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:19:39 by wmardin           #+#    #+#             */
/*   Updated: 2022/06/13 15:42:22 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Checks if the input string is an accepted number format
Requirements:
-	Every character must be a number
-	Only exception is the first character
	-	One sign is allowed as first character ("-" or "+")
	-	If first character is a sign, there must be at least one more character
*/
int	ft_isnumberformat(char *input)
{
	int		i;

	i = 1;
	if (input[0] < 48 || input[0] > 57)
	{
		if (input[0] != 45 && input[0] != 43)
			return (0);
		if (!input[1])
			return (0);
	}
	while (input[i])
	{
		if (input[i] < 47 || input[i] > 57)
			return (0);
		i++;
	}
	return (2);
}