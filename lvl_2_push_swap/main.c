/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:54:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/30 22:43:32 by nnuno-ca         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = init_a(parse_input(argc, argv), (argc - 1));
	b = init_b(argc - 1);
	
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
	
	

	free(a->int_list);
	free(b->int_list);
	free(a);
	free(b);
	return (EXIT_SUCCESS);
}