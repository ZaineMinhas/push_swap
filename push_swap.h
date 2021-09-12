/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:18:33 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/12 16:48:33 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				num;
}					t_stack;

typedef struct	s_var
{
	t_stack	*a;
	t_stack	*b;
}				t_var;

void	init_var(t_var *var);
void	read_args(int ac, char **av, t_var *var);
void	add_stack(int num, t_stack **a);
void	lst_rewind(t_stack **lst);

/*
** SWAP FUNCTIONS
*/

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/*
** PUSH FUNCTIONS
*/

void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);

/*
** ROTATE FUNCTIONS
*/

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/*
** REVERSE ROTATE FUNCTIONS
*/

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/*
** UTILS FUNCTIONS
*/

void	return_error(int index);
void	lst_rewind(t_stack **lst);
void	lst_forward(t_stack **lst);
void	print_lst(t_stack **lst);

#endif