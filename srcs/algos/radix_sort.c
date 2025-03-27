/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:16:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/10 01:31:17 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	simplify_numbers(t_stack *stack, int *sorted_array)
{
	int	i;
	int	*temp;
	int	j;

	i = -1;
	temp = malloc(stack->stack_size * sizeof(int));
	while (++i < stack->stack_size)
	{
		j = -1;
		while (++j < stack->stack_size)
		{
			if (sorted_array[i] == stack->storage[j])
				temp[j] = i;
		}
	}
	i = -1;
	while (++i < stack->stack_size)
		stack->storage[i] = temp[i];
	free(temp);
	free(sorted_array);
}

static int	*gen_sorted_arr(t_stack *stack)
{
	int	*sorted_arr;
	int	i;

	sorted_arr = malloc(stack->stack_size * sizeof(int));
	i = 0;
	while (i < stack->stack_size)
	{
		sorted_arr[i] = stack->storage[i];
		i += 1;
	}
	insertion_sort(sorted_arr, stack->stack_size);
	return (sorted_arr);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	num;
	int	i;
	int	j;

	max_bits = 0;
	simplify_numbers(a, gen_sorted_arr(a));
	num = max(a);
	while ((num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (!is_sorted(a) && (++j < a->stack_size))
		{
			num = a->storage[a->top];
			if (((num >> i) & 0b00000001) == 1)
				ra(a, true);
			else
				pb(a, b);
		}
		while (!is_empty(b))
			pa(a, b);
	}
}
