/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:03:02 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/26 14:53:04 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

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
	int		check;
}				t_var;

void	read_args(int ac, char **av, t_var *var);
void	add_stack(t_var *var, t_stack **a, int num);
void	check_dup(t_var *var, t_stack *lst, int ac);

/*
** SWAP FUNCTIONS
*/

void	sa(t_var *var, t_stack **a);
void	sb(t_var *var, t_stack **b);
void	ss(t_var *var, t_stack **a, t_stack **b);

/*
** PUSH FUNCTIONS
*/

void	pa(t_var *var, t_stack **b, t_stack **a);
void	pb(t_var *var, t_stack **a, t_stack **b);

/*
** ROTATE FUNCTIONS
*/

void	ra(t_var *var, t_stack **a);
void	rb(t_var *var, t_stack **b);
void	rr(t_var *var, t_stack **a, t_stack **b);

/*
** REVERSE ROTATE FUNCTIONS
*/

void	rra(t_var *var, t_stack **a);
void	rrb(t_var *var, t_stack **b);
void	rrr(t_var *var, t_stack **a, t_stack **b);

/*
** UTILS FUNCTIONS
*/

void	return_error(t_var *var, int index);
void	lst_rewind(t_stack **lst);
void	lst_forward(t_stack **lst);
void	print_lst(t_stack *a, t_stack *b);
void	free_lst(t_stack **a, t_stack **b);
int		lstlen(t_stack *lst);

#endif