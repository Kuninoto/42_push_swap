/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:43:34 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/07 01:20:51 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	panic(t_stack *a, t_stack *b)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	if (a)
		free(a->storage);
	if (b)
		free(b->storage);
	exit(EXIT_FAILURE);
}
