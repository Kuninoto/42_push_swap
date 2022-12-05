/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_midpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:31:24 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/05 14:26:48 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	while ((i + chunk_start) < stack->stack_size)
	{
		sorted_arr[i] = stack->int_list[i + chunk_start];			
		i++;
	}
	insertion_sort(sorted_arr, chunk_size);
	mid_point = sorted_arr[(chunk_size / 2)];
	free(sorted_arr);
	sorted_arr = NULL;
	return (mid_point);
}