/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:54:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/10 01:30:27 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	execute_instructions(t_stack *a, t_stack *b, char *instruction)
{
	if (streq(instruction, "sa\n"))
		sa(a);
	else if (streq(instruction, "sb\n"))
		sb(b);
	else if (streq(instruction, "ss\n"))
		ss(a, b);
	else if (streq(instruction, "pa\n"))
		pa(a, b);
	else if (streq(instruction, "pb\n"))
		pb(a, b);
	else if (streq(instruction, "rra\n"))
		rra(a);
	else if (streq(instruction, "rrb\n"))
		rrb(b);
	else if (streq(instruction, "rrr\n"))
		rrr(a, b);
	else if (streq(instruction, "ra\n"))
		ra(a);
	else if (streq(instruction, "rb\n"))
		rb(b);
	else if (streq(instruction, "rr\n"))
		rr(a, b);
	else
		panic(a, b);
}

static void	process_instructions(t_stack *a, t_stack *b)
{
	char	*instruction;

	while (true)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (instruction == NULL)
			break ;
		execute_instructions(a, b, instruction);
		free(instruction);
	}
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;

	if (argc < 2)
		return (EXIT_SUCCESS);
	a = init_a(argc - 1);
	fill_a(&a, parse_input(&a, argc, argv), (argc - 1));
	b = init_b(argc - 1);
	process_instructions(&a, &b);
	if (is_sorted(&a) && is_empty(&b))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	free_stacks(&a, &b);
	return (EXIT_SUCCESS);
}
