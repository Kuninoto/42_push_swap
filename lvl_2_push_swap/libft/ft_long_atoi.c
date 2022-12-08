/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:04:24 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 01:23:29 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_long_atoi(const char *str)
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
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((res * 10) + (str[i] - '0'));
		i++;
	}
	if (res > INT_MAX || res < INT_MIN)
		handle_error();
	return ((int)res * signal);
}
