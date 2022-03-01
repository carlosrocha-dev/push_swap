/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:46:00 by jfrancis          #+#    #+#             */
/*   Updated: 2022/02/28 19:22:43 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/push_swap.h"

void	helper_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	sort_helper(int *arr, int n)
{
	int	i;
	int	j;
	int	sm;

	i = 0;
	while (i < n - 1)
	{
		sm = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[sm])
				sm = j;
			j++;
		}
		helper_swap(&arr[sm], &arr[i]);
		i++;
	}
}

void	init_pivots(int i, t_data *data)
{
	int	j;
	int	*p_i;

	p_i = ft_calloc(i, sizeof (int));
	data->pivots = ft_calloc(i, sizeof (int));
	j = 0;
	while (j < i)
	{
		p_i[j] = data->stack_a.size * (j + 1) / 4;
		data->pivots[j] = data->helper[p_i[j]];
		j++;
	}
}

void	init_helper(t_data *data)
{
	int	i;

	i = 0;
	data->helper = ft_calloc(data->stack_a.size, sizeof (int));
	while (i < data->stack_size)
	{
		data->helper[i] = data->stack_a.elems[i];
		i++;
	}
}

void	sort_hundred(t_data *data)
{
	int	i;
	int	p = 3;

	i = 0;
	init_helper(data);
	sort_helper(data->helper, data->stack_a.size);
	init_pivots(p, data);
	while (i > (data->stack_a.size / 4) )
	{
		divide_stack(i, data);
		i++;
	}
	while (is_sorted(data->stack_a.elems, data->stack_a.size) == 0)
		sort_small(data);
	if (is_sorted(data->stack_a.elems, data->stack_a.size) == 0)
		sort_three(data);
	while (data->stack_b.size > 0)
		conquer_b(data);
}
