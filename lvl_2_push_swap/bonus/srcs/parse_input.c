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

#include "../includes/checker.h"

void	check_duplicates(int *int_list, int arr_len, t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = -1;
	while (++i < arr_len)
	{
		j = i + 1;
		while (j < arr_len)
		{
			if (int_list[i] == int_list[j])
			{
				free(int_list);
				free_arrays(a, b);
				handle_error();
			}
			j++;
		}
	}
}

// Converts all number strings provided to integers
int	*conv_argv_to_int(int argc, char **argv)
{
	int	*int_list;
	int	i;
	int	j;

	int_list = malloc((argc - 1) * sizeof(int));
	i = 0;
	j = 1;
	while (argv[j])
		int_list[i++] = ft_long_atoi(argv[j++]);
	return (int_list);
}

// Checks if all characters provided are digits
void	check_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	if (argc < 2)
	{
		free_arrays(a, b);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != '-') ||
				(argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])))
			{
				free_arrays(a, b);
				handle_error();
			}
		}
	}
}

int	*parse_input(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	*int_list;

	check_args(argc, argv, a, b);
	int_list = conv_argv_to_int(argc, argv);
	check_duplicates(int_list, (argc - 1), a, b);
	return (int_list);
}
