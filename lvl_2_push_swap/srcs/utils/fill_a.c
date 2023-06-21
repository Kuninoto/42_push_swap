/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:55:53 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/09 18:27:39 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicates(t_stack *a, int *storage, int arr_len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < arr_len)
	{
		j = i + 1;
		while (j < arr_len)
		{
			if (storage[i] == storage[j])
			{
				free(storage);
				panic(a, NULL);
			}
			j++;
		}
	}
}

// Converts all number strs provided to integers
static int	*conv_argv_to_int(t_stack *a, int argc, char **argv)
{
	int	*int_list;
	int	i;
	int	j;
	int	nr;

	int_list = malloc((argc - 1) * sizeof(int));
	i = 0;
	j = 1;
	while (argv[j])
	{
		nr = ft_atoll(argv[j]);
		if (nr > INT_MAX || nr <= INT_MIN)
		{
			free(int_list);
			panic(a, NULL);
		}
		int_list[i] = nr;
		i += 1;
		j += 1;
	}
	return (int_list);
}

// Checks whether all characters provided are digits
static void	check_args(char **argv, t_stack *a)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				|| (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])))
				panic(a, NULL);
			j += 1;
		}
		i += 1;
	}
}

static int	*parse_input(t_stack *a, int argc, char **argv)
{
	int	*storage;

	check_args(argv, a);
	storage = conv_argv_to_int(a, argc, argv);
	check_duplicates(a, storage, (argc - 1));
	return (storage);
}

void	fill_a(t_stack *a, int argc, char **argv)
{
	int	i;
	int	*integer_list;

	i = (argc - 1) - 1;
	integer_list = parse_input(a, argc, argv);
	while (i >= 0)
	{
		push(a, integer_list[i]);
		i -= 1;
	}
	free(integer_list);
}
