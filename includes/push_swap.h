/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:18:33 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/18 18:39:11 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				num;
}				t_stack;

typedef struct s_var
{
	t_stack	*a;
	t_stack	*b;
	int		bool;
	int		size;
	int		hold_first;
	int		hold_last;
}				t_var;

void	init_var(t_var *var);
void	read_args(int ac, char **av, t_var *var);
void	add_stack(int num, t_stack **a);
void	sort(t_var *var);
int		sorted(t_stack **a);
void	find_chunks(t_var *var, int div);
void	move_chunk(t_var *var, int min, int max);
int		sort_stack_b(t_stack **b, int num, int len);
int		find_hold_first(t_var *var, int chunk);
int		find_hold_last(t_var *var, int chunk);

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

void	print_lst(t_stack *a, t_stack *b);
void	return_error(int index);
void	lst_rewind(t_stack **lst);
void	lst_forward(t_stack **lst);
int		lstlen(t_stack *lst);
int		find_biggest(t_stack *lst);
int		find_smallest(t_stack *lst);

#endif