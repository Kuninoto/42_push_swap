/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:38:54 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/04 17:59:27 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_duplicates(int *int_list, int arr_len)
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
				handle_error(int_list);
			j++;
		}
	}
}

//converts all number strs provided to integers
int	*conv_argv_to_int(int argc, char **argv)
{
	int	*int_list;
	int	i;
	int	j;

	int_list = malloc((argc - 1) * sizeof(int));
	if (!int_list)
		handle_error(NULL);
	i = 0;
	j = 1;
	while (argv[j])
		int_list[i++] = ft_atoi(argv[j++]);
	return (int_list);
}

//checks whether all characters provided are digits





// NEGATIVE NUMBERS ARE NOT PASSING
void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
			if (ft_isdigit(argv[i][j++]) == 0)
				handle_error(NULL);
	}
}





int	*parse_input(int argc, char **argv)
{
	int	*int_list;

	check_args(argc, argv);
	int_list = conv_argv_to_int(argc, argv);
	check_duplicates(int_list, (argc - 1));
	return (int_list);
}

/*
	MISSING INT MAX/INT MIN CHECK
*/