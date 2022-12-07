/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:54:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/07 03:21:23 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
/* 	t_stack	*a;
	t_stack	*b;

	a = init_a(parse_input(argc, argv), (STACK_SIZE));
	b = init_b(STACK_SIZE);

	free_stacks(a, b); */

	t_vector *my_vec;

	my_vec = vec_new();	
//	printf("INITIAL VECTOR\n");
/* 	for (size_t i = 0; i <= my_vec->count; i++)
		printf("my_vec at %ld = %s\n", i, my_vec->storage[i]); */

	vec_push(my_vec, "Olá\n");
	vec_push(my_vec, "loles\n");
	vec_push(my_vec, "sou o maior\n");
	
	for (size_t i = 0; i < 3; i++)
		printf("my_vec at %ld = %s", i, my_vec->storage[i]);
	
	//free_vec(my_vec);
	return (EXIT_SUCCESS);
}
