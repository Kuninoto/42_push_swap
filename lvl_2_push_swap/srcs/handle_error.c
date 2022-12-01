/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:43:34 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/30 17:54:41 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_error(void *to_free)
{
	free(to_free);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
