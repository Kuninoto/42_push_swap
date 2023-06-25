/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:54:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/09 17:42:16 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (EXIT_SUCCESS);
	a = init_stack(argc - 1);
	fill_a(&a, parse_input(argc, argv, &a), argc);
	b = init_stack(argc - 1);
	if (!is_sorted(&a))
	{
		if (a.stack_size == 3)
			special_case(&a);
		else if (a.stack_size >= 200)
			radix_sort(&a, &b);
		else
			midpoint_sort(&a, &b);
	}
	free_stacks(&a, &b);
	return (EXIT_SUCCESS);
}
