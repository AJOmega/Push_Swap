/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:24:27 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/20 23:55:09 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
	*stack = second;
	return (1);
}

int	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = (*stack)->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*stack = second;
	return (1);
}

int	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*head_1;

	if (!*stack_1)
		return (0);
	head_1 = *stack_1;
	*stack_1 = (*stack_1)->next;
	head_1->next = *stack_2;
	*stack_2 = head_1;
	return (1);
}

int	rev_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*new_last;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = *stack;
	while (last->next)
	{
		new_last = last;
		last = last->next;
	}
	new_last->next = NULL;
	last->next = first;
	*stack = last;
	return (1);
}
