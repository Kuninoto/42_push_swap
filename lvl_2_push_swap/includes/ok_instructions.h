/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_instructions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:05:10 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 21:10:00 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef OK_INSTRUCTIONS_H
# define OK_INSTRUCTIONS_H

bool	ok_sa(t_stack *a);
bool	ok_sb(t_stack *b);

bool	ok_ra(t_stack *a);
bool	ok_rb(t_stack *b);

bool	ok_rra(t_stack *a);
bool	ok_rrb(t_stack *b);

bool	ok_ss(t_stack *a, t_stack *b);
bool	ok_rr(t_stack *a, t_stack *b);
bool	ok_rrr(t_stack *a, t_stack *b);

#endif