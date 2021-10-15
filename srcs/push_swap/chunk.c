/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:46:09 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/15 15:40:06 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_tab(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

void	move_chunk(t_var *var, int min, int max)
{
	int	i;
	int	j;

	i = find_hold_first(var, min, max);
	j = find_hold_last(var, min, max);
	if (i < j)
		while (i--)
			ra(&var->a);
	else
		while (j--)
			rra(&var->a);
	lst_rewind(&var->a);
	i = sort_stack_b(&var->b, var->a->num, lstlen(var->b));
	pb(&var->a, &var->b);
	j = -1;
	if (i == -1)
		rb(&var->b);
	else if (i && i < (lstlen(var->b) - 1) / 2)
		while (++j < i)
			rrb(&var->b);
	else if (i)
		while (++j < lstlen(var->b) - i)
			rb(&var->b);
	lst_rewind(&var->a);
	lst_rewind(&var->b);
}

void	move_all_chunks(t_var *var, int tab_len)
{
	int	i;

	i = -1;
	while (++i <= tab_len / 4)
		move_chunk(var, INT_MIN, var->chunk[0]);
	i--;
	while (++i <= tab_len / 2)
		move_chunk(var, var->chunk[0] + 1, var->chunk[1]);
	i--;
	while (++i <= (tab_len * 3) / 4)
		move_chunk(var, var->chunk[1] + 1, var->chunk[2]);
	i--;
	while (++i <= tab_len)
		move_chunk(var, var->chunk[2] + 1, INT_MAX);
	while (i--)
		pa(&var->b, &var->a);
}

void	find_chunks(t_var *var)
{
	int	*array;
	int	i;

	i = -1;
	lst_rewind(&var->a);
	array = (int *)malloc(sizeof(int) * lstlen(var->a));
	if (!array)
		return_error(0);
	while (++i < lstlen(var->a) - 1)
	{
		array[i] = var->a->num;
		var->a = var->a->next;
	}
	array[i] = var->a->num;
	sort_tab(array, i);
	var->chunk[0] = array[i / 4];
	var->chunk[1] = array[i / 2];
	var->chunk[2] = array[i * 3 / 4];
	move_all_chunks(var, i);
	free(array);
}
