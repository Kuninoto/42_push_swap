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

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(EXIT_FAILURE);
	a = init_a(argc - 1);
	fill_a(&a, argc, argv);
	b = init_b(argc - 1);
	if (isordered(&a))
	{
		free_arrays(&a, &b);
		exit(EXIT_SUCCESS);
	}
	if (a.stack_size == 3)
		special_case(&a, &b);
	else if (a.stack_size >= 200)
		radix_sort(&a, &b);
	else
		midpoint_sort(&a, &b);
	free_arrays(&a, &b);
	return (EXIT_SUCCESS);
}

/* 	
 	int i = a.top + 1;
    int j = b.top + 1;
    while (i--)
    {
        if (j >= 0)
            j--;
        printf("%d  %d\n", a.int_list[i], b.int_list[j]);
    }
    printf("_  _\na  b\n");
*/

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
