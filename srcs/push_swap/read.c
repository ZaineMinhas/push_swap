/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:33:50 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/22 18:01:04 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_dup(t_stack *lst, int ac)
{
	t_stack	*tmp;

	lst_rewind(&lst);
	while (--ac)
	{
		tmp = lst;
		while (lst->next)
		{
			if (tmp->num == lst->next->num)
				return_error(2);
			lst = lst->next;
		}
		lst = tmp->next;
	}
}

void	add_stack(int num, t_stack **a)
{
	if (!*a)
	{
		*a = malloc(sizeof(t_stack));
		if (!*a)
			return_error(0);
		(*a)->num = num;
		(*a)->prev = NULL;
		(*a)->next = NULL;
	}
	else
	{
		(*a)->next = malloc(sizeof(t_stack));
		if (!(*a)->next)
			return_error(0);
		(*a)->next->num = num;
		(*a)->next->prev = *a;
		(*a)->next->next = NULL;
		*a = (*a)->next;
	}
}

void	read_args(int ac, char **av, t_var *var)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_isdigit(av[i][0]) && av[i][0] != '+' && av[i][0] != '-')
			return_error(1);
		add_stack(ft_atoi(av[i]), &var->a);
	}
	check_dup(var->a, ac);
}
