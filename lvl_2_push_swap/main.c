/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:54:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/06 02:25:04 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// moves every number smaller than mid point to stack b
void	move_smaller_top(t_stack *a, t_stack *b, int mid_point)
{
	while (a->int_list[a->top] < mid_point)
		pb(a, b);
}

void	move_smaller_bottom(t_stack *a, t_stack *b, int mid_point)
{
	while (a->int_list[0] < mid_point)
	{
		rra(a);
		pb(a, b);
	}
}

void	divide(t_stack *a, t_stack *b, int mid_point, int nr_chunks)
{
	while ((a->top - 1) > (b->top / nr_chunks))
	{
		if (a->int_list[a->top] < mid_point)
			pb(a, b);
		else
			ra(a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		chunks;
	int		mid_point;

	a = init_a(parse_input(argc, argv), (STACK_SIZE));
	b = init_b(STACK_SIZE);
	chunks = 1;
	while (a->top > 1)
	{
		mid_point = find_midpoint(a, 0);
		printf("mid point = %d\n", mid_point);		
		move_smaller_top(a, b, mid_point);
		move_smaller_bottom(a, b, mid_point);
		divide(a, b, mid_point, chunks++);
	}
	if (a->int_list[a->top] > a->int_list[a->top - 1])
		sa(a);







	printf("\n");

	int i = a->top;
	int j = b->top;
	while (i >= 0 || j >= 0)
	{
		printf("%d %d\n", a->int_list[i], b->int_list[j]);
		if (i >= 0)
			i--;
		j--;
	}
	printf("_ _\n");
	printf("a b\n\n");


	free(a->int_list);
	free(b->int_list);
	free(a);
	free(b);
	return (EXIT_SUCCESS);
}

// 2 3 5 12 10 6 9 7 4 1 8 11

/*
	TEST WITH NEGATIVE INPUT
*/

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