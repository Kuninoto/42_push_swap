/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:54:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/07 21:45:54 by nnuno-ca         ###   ########.fr       */
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
	if (ft_strncmp(instruction, "sa", 2) == 0)
		sa(a);
	else if (ft_strncmp(instruction, "sb", 2) == 0)
		sb(b);
	else if (ft_strncmp(instruction, "ss", 2) == 0)
		ss(a, b);
	else if (ft_strncmp(instruction, "pa", 2) == 0)
		pa(a, b);
	else if (ft_strncmp(instruction, "pb", 2) == 0)
		pb(a, b);
	else if (ft_strncmp(instruction, "rra", 3) == 0)
		rra(a);
	else if (ft_strncmp(instruction, "rrb", 3) == 0)
		rrb(b);
	else if (ft_strncmp(instruction, "rrr", 3) == 0)
		rrr(a, b);
	else if (ft_strncmp(instruction, "ra", 2) == 0)
		ra(a);
	else if (ft_strncmp(instruction, "rb", 2) == 0)
		rb(b);
	else if (ft_strncmp(instruction, "rr", 2) == 0)
		rr(a, b);
}

void	get_instructions(t_vector *vector)
{
	char	*new_instruction;

	while (true)
	{
		new_instruction = get_next_line(STDIN_FILENO);
		if (new_instruction == NULL)
			break ;
		vec_push(vector, new_instruction);
	}
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_vector	instructions_vec;
	size_t		i;

	a = init_a(argc - 1);
	b = init_b(argc - 1);
	fill_a(&a, parse_input(argc, argv), (argc - 1));
	instructions_vec = vec_new();
	get_instructions(&instructions_vec);
	i = 0;
	while (i < instructions_vec.count)
		execute_instructions(&a, &b, instructions_vec.storage[i++]);
	if (isordered(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
//	free_stacks(&a, &b);
	free_vec(&instructions_vec);
	return (EXIT_SUCCESS);
}
