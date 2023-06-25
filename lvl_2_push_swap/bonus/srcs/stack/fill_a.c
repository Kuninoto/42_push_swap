/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:53:51 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 00:53:53 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fill_a(t_stack *a, int *int_arr, int arr_len)
{
	int	i;

	i = arr_len - 1;
	while (i >= 0)
	{
		push(a, int_arr[i]);
		i -= 1;
	}
	free(int_arr);
}
