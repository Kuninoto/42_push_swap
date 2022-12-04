/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:54:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/04 18:41:07 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack *init_b(int arr_len)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (b == NULL)
		handle_error(NULL);
	b->stack_size = arr_len;
	b->int_list = malloc(arr_len * sizeof(int));
	b->top = -1;
	return (b);
}

t_stack *init_a(int *int_arr, int arr_len)
{
	t_stack	*a;
	int		i;
	
	a = malloc(sizeof(t_stack));
	if (a == NULL)
		handle_error(NULL);
	a->stack_size = arr_len;
	a->int_list = malloc(arr_len * sizeof(int));
	a->top = -1;
	i = (arr_len - 1);
	while (i >= 0)
		push(a, int_arr[i--]);;
	free(int_arr);
	return (a);
}

int	find_midpoint(t_stack *stack, int chunk_start)
{
	int		mid_point;
	int		i;
	int		chunk_size;
	int		*sorted_arr;

	mid_point = 0;
	i = 0;
	chunk_size = (stack->top + 1) - chunk_start;
	sorted_arr = malloc(chunk_size * sizeof(int));
	while ((i + chunk_start) < stack->stack_size)
	{
		sorted_arr[i] = stack->int_list[i + chunk_start];			
		i++;
	}
	insertion_sort(sorted_arr, chunk_size);
	printf("sorted_arr = ");
	for (int j = 0; j < 4; j++)
		printf("%d ", sorted_arr[j]);
	printf("\n");
	mid_point = sorted_arr[(chunk_size / 2)];
	free(sorted_arr);
	sorted_arr = NULL;
	return (mid_point);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		mid_point;

	a = init_a(parse_input(argc, argv), (STACK_SIZE));
	b = init_b(STACK_SIZE);
	
	mid_point = find_midpoint(a, 0);
	printf("MID POINT = %d\n", mid_point);

	free(a->int_list);
	free(b->int_list);
	free(a);
	free(b);
	return (EXIT_SUCCESS);
}

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