/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:53:35 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 01:45:48 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	sa(a, false);
	sb(b, false);
	write(STDOUT_FILENO, "ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, false);
	rb(b, false);
	write(STDOUT_FILENO, "rr\n", 3);
}

void	rra(t_stack *a, bool print_instruction)
{
	int	save_last;
	int	i;

	if (isempty(a))
		return ;
	save_last = a->int_list[0];
	i = 0;
	while (i < a->top)
	{
		a->int_list[i] = a->int_list[i + 1];
		i++;
	}
	a->int_list[a->top] = save_last;
	if (print_instruction)
		write(STDOUT_FILENO, "rra\n", 4);
}

void	rrb(t_stack *b, bool print_instruction)
{
	int	save_last;
	int	i;

	if (isempty(b))
		return ;
	save_last = b->int_list[0];
	i = 0;
	while (i < b->top)
	{
		b->int_list[i] = b->int_list[i + 1];
		i++;
	}
	b->int_list[b->top] = save_last;
	if (print_instruction)
		write(STDOUT_FILENO, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, false);
	rrb(b, false);
	write(STDOUT_FILENO, "rrr\n", 4);
}
