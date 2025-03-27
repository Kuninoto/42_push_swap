/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:38:54 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 16:54:11 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a(t_stack *a, int *int_arr, int argc)
{
	int	i;

	i = (argc - 1) - 1;
	while (i >= 0)
	{
		push(a, int_arr[i]);
		i -= 1;
	}
	free(int_arr);
}
