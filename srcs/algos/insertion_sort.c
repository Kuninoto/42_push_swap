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

#include "push_swap.h"

void	insertion_sort(int *storage, int chunk_size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < chunk_size)
	{
		key = storage[i];
		j = i - 1;
		while (j >= 0 && storage[j] > key)
		{
			storage[j + 1] = storage[j];
			j -= 1;
		}
		storage[j + 1] = key;
		i += 1;
	}
}
