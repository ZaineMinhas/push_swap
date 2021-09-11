/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:33:50 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/11 14:42:07 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_stack(int num, t_stack *a)
{
	if (!a)
	{
		a = malloc(sizeof(t_stack));
		if (!a)
			exit(1);
		a->num = num;
		a->prev = NULL;
		a->next = NULL;
	}
	else
	{
		a->next = malloc(sizeof(t_stack));
		if (!a->next)
			exit(1);
		a->next->num = num;
		a->next->prev = a;
		a->next->next = NULL;
	}
	a = a->next;
}

void	read_args(int ac, char **av, t_var *var)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_isdigit(av[i][0]) || av[i][0] != ' ' || \
			av[i][0] != '+' || av[i][0] != '-')
			exit(1);
		add_stack(ft_atoi(av[i]), var->a);
	}
}
