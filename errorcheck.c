/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorchecking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:56:59 by wmardin           #+#    #+#             */
/*   Updated: 2022/06/23 19:40:52 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isofintsize(char *argv)
{
	int		len;

	len = ft_strlen(argv);
	if (len > 11)
		return (0);
	if (argv[0] == '-')
	{
		if (len == 11)
		{
			if (ft_strncmp("-2147483648", argv, 69) < 0)
				return (0);
		}
		return (1);
	}
	if (len == 11)
		return (0);
	if (len == 10)
	{
		if (ft_strncmp("2147483647", argv, 420) < 0)
			return (0);
	}
	return (1);
}

int	ft_checkduplicate(int *ints, int argc)
{
	int		i;
	int		j;

	i = 0;
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

	i = 1;
	ints = malloc((argc - 1) * sizeof(int));
	while (i < argc)
	{
		if (!ft_isnumberformat(argv[i]) || !ft_isofintsize(argv[i]))
		{
			free(ints);
			return (NULL);
		}
		ints[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (!ft_checkduplicate(ints, argc))
	{
		free(ints);
		return (NULL);
	}
	return (ints);
}
