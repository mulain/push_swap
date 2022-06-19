/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorchecking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:56:59 by wmardin           #+#    #+#             */
/*   Updated: 2022/06/19 20:53:19 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isofintsize(int argc, char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		
	}
}

int	ft_checkduplicate(long long *ints, int argc)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i + 1 < argc)
	{
		while (i + 1 < argc)
		{
			if (ints[i] == ints[i + 1])
				return (0);
			i++;
		}
		j++;
		i += j;
	}
	return (1);
}

int	*ft_errorcheck(int argc, char **argv)
{
	int		i;
	int		*ints;

	if (argc < 3)
		return (NULL);
	if (!ft_isofintsize(argc, argv))
		return (NULL);
	i = 0;
	ints = malloc(argc * sizeof(int));
	while (++i < argc)
	{
		if (!ft_isnumberformat(argv[i]))
		{
			free(ints);
			return (NULL);
		}
		ints[i] = ft_atoi(argv[i]);
	}
	if (!ft_checkduplicate(ints, argc))
	{
		free(ints);
		return (NULL);
	}
	return (ints);
}
