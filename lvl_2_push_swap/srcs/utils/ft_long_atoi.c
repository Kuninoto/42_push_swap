/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:04:24 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/09 19:09:50 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_long_atoi(const char *str, t_stack *a, int *int_array)
{
	ssize_t	res;
	int		signal;
	int		i;

	res = 0;
	signal = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			signal = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((res * 10) + (str[i] - '0'));
		i++;
	}
	if (res > INT_MAX || res < INT_MIN)
	{
		free(a->int_list);
		free(int_array);
		handle_error();
	}
	return ((int)res * signal);
}
