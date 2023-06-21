/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:51:35 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/09 17:39:09 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_midpoint(t_stack *stack, int chunk_start)
{
	int		mid_point;
	int		i;
	int		chunk_size;
	int		*sorted_arr;

	mid_point = 0;
	i = 0;
	chunk_size = (stack->top + 1) - chunk_start;
	sorted_arr = malloc(chunk_size * sizeof(int));
	while ((i + chunk_start) < (stack->top + 1))
	{
		sorted_arr[i] = stack->storage[i + chunk_start];
		i += 1;
	}
	insertion_sort(sorted_arr, chunk_size);
	mid_point = sorted_arr[(chunk_size / 2)];
	free(sorted_arr);
	sorted_arr = NULL;
	return (mid_point);
}

void	midpoint_sort(t_stack *a, t_stack *b)
{
	int	chunks;
	int	mid_point;

	chunks = 1;
	if (ok_sa(a))
		sa(a, true);
	while (a->top > 1)
	{
		mid_point = find_midpoint(a, 0);
		move_smaller_top(a, b, mid_point);
		move_smaller_bottom(a, b, mid_point);
		finish_moving(a, b, mid_point, chunks++);
	}
	if (a->storage[a->top] > a->storage[a->top - 1])
		sa(a, true);
	while (b->top != -1)
		move_bigger_top(b, a, max(b));
}
