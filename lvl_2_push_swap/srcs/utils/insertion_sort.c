/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:36:50 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 01:10:20 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	insertion_sort(int *int_list, int chunk_size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < chunk_size)
	{
		key = int_list[i];
		j = i - 1;
		while (j >= 0 && int_list[j] > key)
		{
			int_list[j + 1] = int_list[j];
			j--;
		}
		int_list[j + 1] = key;
		i++;
	}
}
