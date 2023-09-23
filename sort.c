/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:23:07 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/23 04:29:26 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if a tree element list is sorted
int	is_sorted(t_list **list)
{
	int	first;
	int	second;
	int	third;

	first = (*list)->data;
	second = (*list)->next->data;
	third = (*list)->next->next->data;
	return (first < second && second < third);
}

void	small_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
	{
		rotate (stack_a);
		write (1, "ra\n", 3);
	}
	if (size == 3)
		sort_3(stack_a, stack_b);
	if (size > 3 && size <= 5)
		sort_5(stack_a, stack_b);
}

/**
 * cases 3 numbers optimal performance
 * 
 * "2 1 0"	//ra sa
 * "2 0 1" //ra
 * "1 2 0" //rra
 * "1 0 2" //sa
 * "0 2 1" //rra sa
*/
void	sort_3(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->data > (*stack_a)->next->data && \
		(*stack_a)->data > (*stack_a)->next->next->data)
	{
		execute_move("ra", stack_a, stack_b);
		if ((*stack_a)->next->data < (*stack_a)->next->next->data \
			&& !is_sorted(stack_a))
			execute_move("sa", stack_a, stack_b);
		return ;
	}
	if (((*stack_a)->data < (*stack_a)->next->data) && \
		((*stack_a)->next->data > (*stack_a)->next->next->data) \
			&& !is_sorted(stack_a))
	{
		execute_move("rra", stack_a, stack_b);
		if ((*stack_a)->next->data < (*stack_a)->next->next->data \
			&& !is_sorted(stack_a))
			execute_move("sa", stack_a, stack_b);
		return ;
	}
	execute_move("sa", stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		barrier;

	size = ft_lstsize(*stack_a);
	barrier = 0 + (size == 5);
	while (size > 3)
	{
		if ((*stack_a)->index <= barrier)
		{
			execute_move("pb", stack_a, stack_b);
			size--;
		}
		else 
			execute_move("ra", stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		sort_3(stack_a, stack_b);
	if ((*stack_b)->next && (*stack_b)->index < (*stack_b)->next->index)
		execute_move("sb", stack_a, stack_b);
	size = ft_lstsize(*stack_b);
	while (size)
	{
		execute_move("pa", stack_a, stack_b);
		size--;
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0) 
		++max_bits;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index) >> i) & 1) 
				execute_move("ra", stack_a, stack_b);
			else 
				execute_move("pb", stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			execute_move("pa", stack_a, stack_b);
		i++;
	}
}
