/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:38:54 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 16:54:11 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	has_duplicates(int *storage, int arr_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_len)
	{
		j = i + 1;
		while (j < arr_len)
		{
			if (storage[i] == storage[j])
				return (true);
			j += 1;
		}
		i += 1;
	}
	return (false);
}

// Converts all number strings provided to integers
static int	*conv_argv_to_int(t_stack *a, int argc, char **argv)
{
	int		*int_list;
	int		i;
	int		j;
	ssize_t	nr;

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
		int_list[i] = (int)nr;
		i += 1;
		j += 1;
	}
	return (int_list);
}

// Checks if all characters provided are digits
static bool	is_all_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != '-') ||
				(argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])))
				return (false);
			j += 1;
		}
		i += 1;
	}
	return (true);
}

int	*parse_input(int argc, char **argv, t_stack *a)
{
	int	*storage;

	if (!is_all_digits(argv))
		panic(a, NULL);
	storage = conv_argv_to_int(a, argc, argv);
	if (has_duplicates(storage, (argc - 1)))
	{
		free(storage);
		panic(a, NULL);
	}
	return (storage);
}
