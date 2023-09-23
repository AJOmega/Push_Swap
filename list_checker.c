/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:06:52 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/16 19:40:57 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find Duplicated numbers

void	check_duplicates(t_list **list)
{
	t_list	*head;
	t_list	*temp;

	head = *list;
	while (head->next)
	{
		temp = head->next;
		while (temp)
		{
			if (head->data == temp->data)
				print_error("Error", list);
			temp = temp->next;
		}
		head = head->next;
	}
}

// Verify if the order is already correct

void	check_order(t_list **list)
{
	t_list	*head;
	int		sorted;

	sorted = 1;
	head = *list;
	while (head->next)
	{
		if (head->data > (head->next)->data)
			sorted = 0;
		head = head->next;
	}
	if (sorted)
	{
		write(1, "\n", 1);
		free_list(list);
	}
}

void	check_list(t_list **list)
{
	check_duplicates(list);
	check_order(list);
}
