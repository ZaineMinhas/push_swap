/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:18:33 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/11 14:42:18 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

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
void	add_stack(int num, t_stack *a);

#endif