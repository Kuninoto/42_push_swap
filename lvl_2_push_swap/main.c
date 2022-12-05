/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:54:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/05 01:03:52 by nnuno-ca         ###   ########.fr       */
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

/*
	find mid point
	everything less than midpoint goes for stack b

	
*/

void	move_smaller_bottom(t_stack *a, t_stack *b, int mid_point)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->int_list[i] < mid_point)
		{
			rra(a);
			pb(a, b);
		}
	}
}

bool	is_bottom_smaller(t_stack *stack, int mid_point)
{
	if (stack->int_list[0] < mid_point)
		return (true);
	else
		return (false);
}

// moves every number smaller than mid point to stack b
void	move_smaller_top(t_stack *a, t_stack *b, int mid_point)
{
	int	i;

	i = a->top;
	while (i > 0)
	{
		if (a->int_list[i] < mid_point)
			pb(a, b);
		else if (is_bottom_smaller(a, mid_point) == true)
			move_smaller_bottom(a, b, mid_point);
		else
		{
			while (a->int_list[a->top] >= mid_point)
				ra(a);
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		mid_point;

	a = init_a(parse_input(argc, argv), (STACK_SIZE));
	b = init_b(STACK_SIZE);
	mid_point = find_midpoint(a, 0);
	
	printf("mid point = %d\n", mid_point);


	printf("Init a and b:\n");	
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


	move_smaller_top(a, b, mid_point);
	
	printf("\n");

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