/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:07:14 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/20 17:22:19 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_index(t_list **stack)
{
	t_list	*head;
	t_list	*current;
	t_list	*temp;
	int		index;

	head = *stack;
	current = *stack;
	temp = head;
	while (current)
	{
		index = 0;
		while (head)
		{
			if (current->data > head->data)
				index++;
			head = head->next;
		}
		current->index = index;
		current = current->next;
		head = temp;
	}
}

void	start_sorting(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	fill_index(stack_a);
	if (size <= 5)
		small_sort(stack_a, stack_b, size);
	else
		radix_sort(stack_a, stack_b);
}
