/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:36:50 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/04 18:05:30 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void insertion_sort(int *int_list, int chunk_size)
{
	int i;
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
			j -= 1;
		}
		int_list[j + 1] = key;
		i++;
	}
}