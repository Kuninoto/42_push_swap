/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:54:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 01:55:01 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		chunks;
	int		mid_point;

	a = init_a(argc - 1);
	b = init_b(argc - 1);
	fill_a(&a, parse_input(argc, argv, &a, &b), (argc - 1));
	chunks = 1;
	if (isordered(&a))
	{
		free_arrays(&a, &b);
		exit(EXIT_SUCCESS);
	}
	if (a.stack_size == 3)
		special_case(&a, &b);
	if (a.int_list[a.top] > a.int_list[a.top - 1])
		sa(&a, true);
	while (a.top > 1)
	{
		mid_point = find_midpoint(&a, 0);
		move_smaller_top(&a, &b, mid_point);
		move_smaller_bottom(&a, &b, mid_point);
		finish_moving(&a, &b, mid_point, chunks++);
	}
	if (a.int_list[a.top] > a.int_list[a.top - 1])
		sa(&a, true);
	while (b.top != -1)
		move_bigger_top(&b, &a, find_maxpoint(&b));
	free_arrays(&a, &b);
	return (EXIT_SUCCESS);
}

// 2 3 5 12 10 6 9 7 4 1 8 11

/* int i = a.top;
	while (i >= 0)
	{
		printf("%d\n", a.int_list[i]);
		if (i >= 0)
			i--;
	}
	printf("_ _\n");
	printf("a b\n\n"); */

/* printf("Init a and b:\n");
	
	int i = a->top;
	int j = b->top;
	while (i >= 0)
	{
		printf("%d %d\n", a->int_list[i], b->int_list[j]);
		if (j > 0)
			j--;
		i--;
	}
	printf("_ _\n");
	printf("a b\n\n");
	
	sa(a);

	printf("Exec sa:\n");

	i = a->top;
	j = b->top;
	while (i >= 0)
	{
		printf("%d %d\n", a->int_list[i], b->int_list[j]);
		if (j > 0)
			j--;
		i--;
	}
	printf("_ _\n");
	printf("a b\n\n");

	pb(a, b);
	pb(a, b);
	pb(a, b);

	printf("Exec pb pb pb:\n");

	i = a->top;
	j = b->top;
	while (i >= 0)
	{
		printf("%d %d\n", a->int_list[i], b->int_list[j]);
		if (j > 0)
			j--;
		i--;
	}
	printf("_ _\n");
	printf("a b\n\n");

	ra(a);
	rb(b);
	
	printf("Exec ra rb:\n");

	i = a->top;
	j = b->top;
	while (i >= 0)
	{
		printf("%d %d\n", a->int_list[i], b->int_list[j]);
		if (j > 0)
			j--;
		i--;
	}
	printf("_ _\n");
	printf("a b\n\n");

	rra(a);
	rrb(b);
	
	printf("Exec rra rrb:\n");

	i = a->top;
	j = b->top;
	while (i >= 0)
	{
		printf("%d %d\n", a->int_list[i], b->int_list[j]);
		if (j > 0)
			j--;
		i--;
	}
	printf("_ _\n");
	printf("a b\n\n");

	sa(a);
	
	printf("Exec sa:\n");

	i = a->top;
	j = b->top;
	while (i >= 0)
	{
		printf("%d %d\n", a->int_list[i], b->int_list[j]);
		if (j > 0)
			j--;
		i--;
	}
	printf("_ _\n");
	printf("a b\n\n");

	pa(a, b);
	pa(a, b);
	pa(a, b);
	
	printf("Exec pa pa pa:\n");

	i = a->top;
	j = b->top;
	while (i >= 0)
	{
		printf("%d %d\n", a->int_list[i], b->int_list[j]);
		if (j > 0)
			j--;
		i--;
	}
	printf("_ _\n");
	printf("a b\n\n"); */