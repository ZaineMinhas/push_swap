/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:33:50 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/26 14:24:25 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_dup(t_var *var, t_stack *lst, int ac)
{
	t_stack	*tmp;

	lst_rewind(&lst);
	while (--ac)
	{
		tmp = lst;
		while (lst->next)
		{
			if (tmp->num == lst->next->num)
				return_error(var, 2);
			lst = lst->next;
		}
		lst = tmp->next;
	}
}

void	add_stack(t_var *var, t_stack **a, int num)
{
	if (!*a)
	{
		*a = malloc(sizeof(t_stack));
		if (!*a)
			return_error(var, 0);
		(*a)->num = num;
		(*a)->prev = NULL;
		(*a)->next = NULL;
	}
	else
	{
		(*a)->next = malloc(sizeof(t_stack));
		if (!(*a)->next)
			return_error(var, 0);
		(*a)->next->num = num;
		(*a)->next->prev = *a;
		(*a)->next->next = NULL;
		*a = (*a)->next;
	}
}

void	read_args(int ac, char **av, t_var *var)
{
	int	i;
	int	j;
	int	first_char;

	i = 0;
	while (++i < ac)
	{
		first_char = 0;
		if (!av[i][0])
			return_error(var, 1);
		j = -1;
		while (av[i][++j])
		{
			if (!first_char && !ft_isdigit(av[i][j]) && \
			av[i][j] != '+' && av[i][j] != '-')
				return_error(var, 1);
			else if (first_char && !ft_isdigit(av[i][j]))
				return_error(var, 1);
			first_char = 1;
		}
		add_stack(var, &var->a, ft_atoi(av[i]));
	}
	check_dup(var, var->a, ac);
}
