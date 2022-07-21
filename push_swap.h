/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:58:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/21 08:58:03 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft/include/libft.h"
# include <stdio.h> //REMOVE HEADER LÖIUBLÖIUBÖIOUBÖOUBÖOUBÖOUB

//util_setup
int		*ft_makeintarray(int argc, char **argv);
int		ft_checkduplicate(int *ints, int argc);
int		ft_isofintsize(char *argv);
t_list	*ft_makestack_a(int argc, char **argv);
void	ft_free_stack(t_list **stack);

//util_assignrank
void	ft_assignrank(t_list **stack_a, int argc);
t_list	*ft_getfirstunranked(t_list **stack);

//algo_util_check
int		ft_checkifordered(t_list **stack, int argc);
int		ft_checkifdone(t_list **stack_a, t_list **stack_b, int argc);

//algo_util_set
void	ft_setnextunordered(t_list **stack, int argc);

//algo_main
void	ft_makeslices(t_list **stack_a, t_list **stack_b, int argc);
void	ft_pushback(t_list **stack_a, t_list **stack_b);
void	ft_finalrotation(t_list **stack);

//algo_utils_get
int		ft_getrankdelta(int i, int j);
int		ft_getrotatedir(t_list **stack, int noderank);
int		ft_getinsertionrank(t_list **stack, int noderank, int argc);
int		ft_getswappable(t_list **stack_a, t_list **stack_b, int argc);

//util_operations
void	ft_swap(t_list **stack);
void	ft_push(t_list **stack_from, t_list **stack_to);
void	ft_rotate(t_list **stack);
void	ft_revrotate(t_list **stack);

//do* files
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