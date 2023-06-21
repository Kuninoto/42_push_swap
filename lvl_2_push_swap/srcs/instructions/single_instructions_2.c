/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_instructions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:46:51 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 01:47:06 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *a, bool print_instruction)
{
	int	save_first;
	int	i;

	if (is_empty(a))
		return ;
	save_first = a->storage[a->top];
	i = a->top;
	while (i > 0)
	{
		a->storage[i] = a->storage[i - 1];
		i--;
	}
	a->storage[BOTTOM] = save_first;
	if (print_instruction)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_stack *b, bool print_instruction)
{
	int	save_first;
	int	i;

	if (is_empty(b))
		return ;
	save_first = b->storage[b->top];
	i = b->top;
	while (i > 0)
	{
		b->storage[i] = b->storage[i - 1];
		i--;
	}
	b->storage[BOTTOM] = save_first;
	if (print_instruction)
		write(STDOUT_FILENO, "rb\n", 3);
}
