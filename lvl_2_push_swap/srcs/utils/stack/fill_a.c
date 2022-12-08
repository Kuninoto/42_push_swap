/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:55:53 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 00:56:06 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	fill_a(t_stack *a, int *int_arr, int arr_len)
{
	int	i;

	i = arr_len - 1;
	while (i >= 0)
		push(a, int_arr[i--]);
	free(int_arr);
}
