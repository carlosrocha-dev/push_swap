/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:28:06 by jfrancis          #+#    #+#             */
/*   Updated: 2022/01/20 20:46:19 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_push_swap(argc, argv, &data);
	destroy_stacks(&data);
	free(data.stack);
	return (0);
}
