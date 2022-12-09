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

#include "../../../includes/push_swap.h"

void	check_duplicates(t_stack *a, int *int_list, int arr_len)
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
				free(a->int_list);
				free(int_list);
				handle_error();
			}
			j++;
		}
	}
}

// Converts all number strs provided to integers
int	*conv_argv_to_int(t_stack *a, int argc, char **argv)
{
	int	*int_list;
	int	i;
	int	j;
	int	temp;

	int_list = malloc((argc - 1) * sizeof(int));
	i = 0;
	j = 1;
	while (argv[j])
	{
		temp = ft_long_atoi(argv[j], a, int_list);
		if (temp == 0 && argv[j][0] != '0')
		{
			free(a->int_list);
			free(int_list);
			handle_error();
		}
		int_list[i++] = ft_long_atoi(argv[j++], a, int_list);
	}
	return (int_list);
}

// Checks whether all characters provided are digits
void	check_args(char **argv, t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				|| (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])))
			{
				free(a->int_list);
				handle_error();
			}
		}
	}
}

int	*parse_input(t_stack *a, int argc, char **argv)
{
	int	*int_list;

	check_args(argv, a);
	int_list = conv_argv_to_int(a, argc, argv);
	check_duplicates(a, int_list, (argc - 1));
	return (int_list);
}

void	fill_a(t_stack *a, int argc, char **argv)
{
	int	i;
	int	*int_arr;

	i = (argc - 1) - 1;
	int_arr = parse_input(a, argc, argv);
	while (i >= 0)
		push(a, int_arr[i--]);
	free(int_arr);
}
