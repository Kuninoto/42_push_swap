/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:16:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/09 19:58:05 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	simplify_numbers(t_stack *stack, int *sorted_array)
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
			if (sorted_array[i] == stack->int_list[j])
				temp[j] = i;
		}
	}
	i = -1;
	while (++i < stack->stack_size)
		stack->int_list[i] = temp[i];
	free(temp);
	free(sorted_array);
}

int	*get_sorted_arr(t_stack *stack)
{
	int		i;
	int		*sorted_arr;

	i = -1;
	sorted_arr = malloc(stack->stack_size * sizeof(int));
	while (++i < stack->stack_size)
		sorted_arr[i] = stack->int_list[i];
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
	simplify_numbers(a, get_sorted_arr(a));
	num = find_maxpoint(a);
	while ((num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (!isordered(a) && (++j < a->stack_size))
		{
			num = a->int_list[a->top];
			if (((num >> i) & 0b00000001) == 1)
				ra(a, true);
			else
				pb(a, b);
		}
		while (!isempty(b))
			pa(a, b);
	}
}


