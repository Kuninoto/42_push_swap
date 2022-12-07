/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:05:35 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/07 20:45:51 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

void	fill_a(t_stack *a, int *int_arr, int arr_len)
{
	int	i;

	i = (arr_len - 1);
	while (i >= 0)
		push(a, int_arr[i--]);
	free(int_arr);
}
