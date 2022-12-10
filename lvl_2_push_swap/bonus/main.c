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

#include "includes/checker.h"

bool	isordered(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->int_list[i] < a->int_list[i + 1])
			return (false);
		i++;
	}
	return (true);
}

void	execute_instructions(t_stack *a, t_stack *b, char *instruction)
{
	size_t	len;

	len = ft_strlen(instruction);
	if (ft_strncmp(instruction, "sa", len - 1) == 0)
		sa(a);
	else if (ft_strncmp(instruction, "sb", len - 1) == 0)
		sb(b);
	else if (ft_strncmp(instruction, "ss", len - 1) == 0)
		ss(a, b);
	else if (ft_strncmp(instruction, "pa", len - 1) == 0)
		pa(a, b);
	else if (ft_strncmp(instruction, "pb", len - 1) == 0)
		pb(a, b);
	else if (ft_strncmp(instruction, "rra", len - 1) == 0)
		rra(a);
	else if (ft_strncmp(instruction, "rrb", len - 1) == 0)
		rrb(b);
	else if (ft_strncmp(instruction, "rrr", len - 1) == 0)
		rrr(a, b);
	else if (ft_strncmp(instruction, "ra", len - 1) == 0)
		ra(a);
	else if (ft_strncmp(instruction, "rb", len - 1) == 0)
		rb(b);
	else if (ft_strncmp(instruction, "rr", len - 1) == 0)
		rr(a, b);
	else
	{
		free_arrays(a, b);
		handle_error();
	}
}

void	get_instructions(t_stack *a, t_stack *b)
{
	char	*new_instruction;

	while (true)
	{
		new_instruction = get_next_line(STDIN_FILENO);
		if (new_instruction == NULL)
			break ;
		execute_instructions(a, b, new_instruction);
		free(new_instruction);
	}
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;

	a = init_a(argc - 1);
	b = init_b(argc - 1);
	fill_a(&a, parse_input(argc, argv, &a, &b), (argc - 1));
	get_instructions(&a, &b);
	if ((isordered(&a) == true) && isempty(&b))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	free_arrays(&a, &b);
	return (EXIT_SUCCESS);
}
