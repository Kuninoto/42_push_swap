/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:54:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 19:24:28 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

/* bool	isordered(t_stack *a)
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

void	execute_instructions(t_stack *a, t_stack *b, char *instruction, t_vector *vector)
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
		free_vec(vector);
		handle_error();
	}
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
	fill_a(&a, parse_input(argc, argv, &a, &b), (argc - 1));
	instructions_vec = vec_new();
	get_instructions(&instructions_vec);
	i = 0;
	while (i < instructions_vec.count)
		execute_instructions(&a, &b, instructions_vec.storage[i++], &instructions_vec);
	if (isordered(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_arrays(&a, &b);
	free_vec(&instructions_vec);
	return (EXIT_SUCCESS);
} */

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
	if ((isordered(&a) == true) && (b.top == -1))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	free_arrays(&a, &b);
	return (EXIT_SUCCESS);
}
