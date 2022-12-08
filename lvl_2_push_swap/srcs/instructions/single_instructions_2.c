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

	if (isempty(a))
		return ;
	save_first = a->int_list[a->top];
	i = a->top;
	while (i > 0)
	{
		a->int_list[i] = a->int_list[i - 1];
		i--;
	}
	a->int_list[0] = save_first;
	if (print_instruction)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_stack *b, bool print_instruction)
{
	int	save_first;
	int	i;

	if (isempty(b))
		return ;
	save_first = b->int_list[b->top];
	i = b->top;
	while (i > 0)
	{
		b->int_list[i] = b->int_list[i - 1];
		i--;
	}
	b->int_list[0] = save_first;
	if (print_instruction)
		write(STDOUT_FILENO, "rb\n", 3);
}
