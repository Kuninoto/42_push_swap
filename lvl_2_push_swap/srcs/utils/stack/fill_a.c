#include "../../../includes/push_swap.h"

void	fill_a(t_stack *a, int *int_arr, int arr_len)
{
	int	i;

	i = arr_len - 1;
	while (i >= 0)
		push(a, int_arr[i--]);
	free(int_arr);
}