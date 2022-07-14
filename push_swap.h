/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:58:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/14 21:13:57 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft/include/libft.h"
# include <stdio.h> //REMOVE HEADER LÖIUBLÖIUBÖIOUBÖOUBÖOUBÖOUB

int		*ft_errorcheck(int argc, char **argv);
int		ft_checkduplicate(int *ints, int argc);
int		ft_isofintsize(char *argv);
t_list	*ft_makestack_a(int *ints, int argc);

void	ft_swap(t_list **stack);
void	ft_push(t_list **stack_from, t_list **stack_to);
void	ft_rotate(t_list **stack);
void	ft_revrotate(t_list **stack);

void	ft_do_swap_a(t_list **stack);
void	ft_do_swap_b(t_list **stack);
void	ft_do_swap_ab(t_list **stack_a, t_list **stack_b);

void	ft_do_push_a(t_list **stack_a, t_list **stack_b);
void	ft_do_push_b(t_list **stack_a, t_list **stack_b);

void	ft_do_rotate_a(t_list **stack);
void	ft_do_rotate_b(t_list **stack);
void	ft_do_rotate_ab(t_list **stack_a, t_list **stack_b);

void	ft_do_revrotate_a(t_list **stack);
void	ft_do_revrotate_b(t_list **stack);
void	ft_do_revrotate_ab(t_list **stack_a, t_list **stack_b);

#endif