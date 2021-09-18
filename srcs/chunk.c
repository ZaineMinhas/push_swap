/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:46:09 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/18 19:18:04 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	find_hold_first(t_var *var, int min, int max)
{
	int	i;

	i = 0;
	lst_rewind(&var->a);
	while (var->a->next)
	{
		if (var->a->num <= max && var->a->num >= min)
		{
			var->hold_first = var->a->num;
			break ;
		}
		i++;
		var->a = var->a->next;
	}
	return (i);
}

int	find_hold_last(t_var *var, int min, int max)
{
	int	i;

	i = 0;
	lst_forward(&var->a);
	while (var->a->prev)
	{
		if (var->a->num <= max && var->a->num >= min)
		{
			var->hold_last = var->a->num;
			break ;
		}
		i++;
		var->a = var->a->prev;
	}
	return (++i);
}

void	move_chunk(t_var *var)
{
	int	i;
	int	j;

	i = find_hold_first(var, INT_MIN, var->quarter);
	j = find_hold_last(var, INT_MIN, var->quarter);
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
	var->quarter = array[i / 4];
	var->half = array[i / 2];
	var->third = array[i * 3 / 4];
	free(array);
	move_chunk(var);
}
