/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:23:07 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/21 00:03:09 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * cases 3 numbers optimal performance
 * 
 * "2 1 0"	//ra sa
 * "2 0 1" //ra
 * "1 2 0" //rra
 * "1 0 2" //sa
 * "0 2 1" //rra sa
*/

void	small_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	if (size == 3)
		sort_3(stack_a, stack_b);
}