/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:51:51 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/12 18:34:28 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	return_error(int index)
{
	if (!index)
		ft_putstr_fd("Malloc error\n", 1);
	if (index == 1)
		ft_putstr_fd("Wrong argument\n", 1);
	if (index == 2)
		ft_putstr_fd("Duplicate argument\n", 1);
	exit(1);
}

void	lst_rewind(t_stack **lst)
{
	if (*lst)
		while ((*lst)->prev)
			*lst = (*lst)->prev;
}

void	lst_forward(t_stack **lst)
{
	if (*lst)
		while ((*lst)->next)
			*lst = (*lst)->next;
}

void	print_lst(t_stack **lst)
{
	if (!*lst)
	{
		printf("non\n");
		return ;
	}
	lst_rewind(lst);
	while ((*lst)->next)
	{
		printf("%d\n", (*lst)->num);
		*lst = (*lst)->next;
	}
	ft_putnbr_fd((*lst)->num, 1);
	ft_putchar_fd('\n', 1);
}
