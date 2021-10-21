/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:22:08 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/21 17:22:25 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	checker(t_var *var)
{
	t_stack	*tmp;

	if (var->b)
		return ;
	lst_rewind(&var->a);
	tmp = var->a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return ;
		tmp = tmp->next;
	}
	ft_putendl_fd("OK", 1);
	exit(1);
}

static void	do_things2(t_var *var, char *line)
{
	if (!ft_strncmp(line, "ra", 3))
		ra(&var->a);
	else if (!ft_strncmp(line, "rb", 3))
		rb(&var->b);
	else if (!ft_strncmp(line, "rr", 3))
		rr(&var->a, &var->b);
	else if (!ft_strncmp(line, "rra", 4))
		rra(&var->a);
	else if (!ft_strncmp(line, "rrb", 4))
		rrb(&var->b);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr(&var->a, &var->b);
}

static void	do_things(t_var *var)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		lst_rewind(&var->a);
		if (!ft_strncmp(line, "sa", 3))
			sa(&var->a);
		else if (!ft_strncmp(line, "sb", 3))
			sb(&var->b);
		else if (!ft_strncmp(line, "ss", 3))
			ss(&var->a, &var->b);
		else if (!ft_strncmp(line, "pa", 3))
			pa(&var->b, &var->a);
		else if (!ft_strncmp(line, "pb", 3))
			pb(&var->a, &var->b);
		else if (!ft_strncmp(line, "\0", 2))
			break ;
		do_things2(var, line);
		lst_rewind(&var->a);
		free(line);
		line = NULL;
		checker(var);
	}
}

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc == 1)
		return (1);
	read_args(argc, argv, &var);
	do_things(&var);
	checker(&var);
	ft_putendl_fd("KO", 1);
	exit(1);
	return (0);
}
