/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:46:09 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/18 18:57:50 by zminhas          ###   ########.fr       */
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
	i = -1;
	while (++i <= size)
		printf("%d ", array[i]);
	printf("\n\n");
}

/*void	move_chunk(t_var *var, int chunk)
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
}*/

void	use_chunk(t_var *var, int chunk, int div)
{
	int	chunk_len;
	int	i;
	int	j;

	chunk_len = var->size / div;
	printf("len = %d / %d == %d\n", var->size, div, var->size / div);
	lst_rewind(&var->a);
	while (chunk_len--)
	{
		i = find_hold_first(var, chunk);
		j = find_hold_last(var, chunk);
		printf("first == %d || %d == last\n", i , j);
		if (i < j)
			while (i--)
				ra(&var->a);
		else
			while (j--)
				rra(&var->a);
		pb(&var->a, &var->b);
		print_lst(var->a, var->b);
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
	{
		if (i == div)
		{
			printf("\nSALUT\n");/*
			lst_rewind(&var->a);
			while (var->a->next)
			{
				pb(&var->a, &var->b);
				var->a = var->a->next;
			}
			pb(&var->a, &var->b);
			printf("yo\n");*/
		}
		printf("CHUNK = %d\n", array[var->size * i / div]);
		//print_lst(var->a, var->b);
		use_chunk(var, array[var->size * i / div], div);
	}
	free(array);
}
