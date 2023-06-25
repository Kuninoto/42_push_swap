/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:36:50 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 01:10:20 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_atoll(const char *str)
{
	ssize_t	res;
	int		signal;
	int		i;

	res = 0;
	signal = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i += 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signal = -1;
			i += 1;
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((res * 10) + (str[i] - '0'));
		i += 1;
	}
	return (res * signal);
}
