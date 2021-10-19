/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:46:09 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/19 19:31:24 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_tab(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - i)
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

void	use_chunk(t_var *var, int chunk, int div)
{
	int	chunk_len;
	int	i;
	int	j;

	chunk_len = var->size / div + 1;
	lst_rewind(&var->a);
	while (chunk_len-- && var->a)
	{
		i = find_hold_first_a(var, chunk);
		j = find_hold_last_a(var, chunk);
		if (i < j)
			while (i--)
				ra(&var->a);
		else
			while (j--)
				rra(&var->a);
		pb(&var->a, &var->b);
	}
}

void	find_chunks(t_var *var, int div)
{
	int	*array;
	int	i;

	lst_rewind(&var->a);
	array = (int *)malloc(sizeof(int) * lstlen(var->a));
	if (!array)
		return_error(0);
	var->size = -1;
	while (++var->size < lstlen(var->a) - 1)
	{
		array[var->size] = var->a->num;
		var->a = var->a->next;
	}
	array[var->size] = var->a->num;
	sort_tab(array, var->size);
	i = 0;
	while (++i <= div)
		use_chunk(var, array[var->size * i / div], div);
	var->size++;
	while (var->size--)
		sort_stack_a(var, array[var->size]);
	free(array);
}
