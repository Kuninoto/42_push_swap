/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:42:19 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/05 19:11:29 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *init_b(int arr_len)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
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
	if (!a)
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
