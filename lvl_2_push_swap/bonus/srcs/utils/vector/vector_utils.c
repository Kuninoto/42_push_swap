/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:34:52 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/07 03:25:05 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

t_vector	*vec_new(void)
{
	t_vector	*new_vector;

	new_vector = malloc(sizeof(t_vector));
	if (!new_vector)
		return (NULL);
	new_vector->count = 0;
	new_vector->capacity = 1;
	new_vector->storage = malloc(sizeof(char *));
	if (!new_vector->storage)
	{
		free_vec(new_vector);
		return (NULL);
	}
	return (new_vector);
}

void	vec_push(t_vector *vector, char	*instruction)
{
	int		vec_index;
	int		save_count;

	if (vector->count == 0)
		vec_index = 0;
	else
		vec_index = vector->count - 1;
	save_count = vector->count;
	if ((vector->count + 1) > vector->capacity)
		vector = vec_realloc(vector);
	vector->storage[vec_index] = instruction;
	vector->count = save_count + 1;
//	printf("vector count = %ld\n", vector->count);
}

char	*vec_pop(t_vector *vector)
{
	char	*instruction;

	instruction = vector->storage[vector->count - 1];
	free(vector->storage[vector->count - 1]);
	vector->count--;
	return (instruction);
}

t_vector	*vec_realloc(t_vector *vector)
{
	t_vector	*resized_vector;
	size_t		i;

	resized_vector = malloc(sizeof(t_vector));
	if (!resized_vector)
	{
		free_vec(resized_vector);
		return (NULL);
	}
	resized_vector->count = vector->count;
	resized_vector->capacity = vector->capacity * 2;
	resized_vector->storage = malloc((vector->capacity * 2) * sizeof(char *));
	if (!resized_vector->storage)
	{
		ft_putstr_fd("Failed to resize vector\n", 2);
		free_vec(resized_vector);
		return (NULL);
	}
	i = 0;
	while (i < resized_vector->count)
	{
		resized_vector->storage[i] = vector->storage[i];
		i++;
	}
	free(vector);
	return (resized_vector);
}

void	free_vec(t_vector *vector)
{
	size_t	i;

	i = 0;
	if (vector)
	{
		if (vector->storage)
		{
			if (vector->count > 1)
			{
				while (i < vector->count)
				{
					free(vector->storage[i]);
					i++;
				}
			}
			free(vector->storage);
		}
		free(vector);
	}
}
