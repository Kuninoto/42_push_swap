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

#include "checker.h"

void	panic(t_stack *a, t_stack *b)
{
	ft_putendl_fd("Error", 2);
	free(a->storage);
	free(b->storage);
	exit(EXIT_FAILURE);
}
