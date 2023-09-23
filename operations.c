/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:09:11 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/21 00:31:34 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_move(char *ptr, t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	sucess;

	sucess = 0;
	size = ft_strlen(ptr);
	if (!ft_strncmp("ra", ptr, size))
		sucess = rotate(stack_a);
	else if (!ft_strncmp("rb", ptr, size))
		sucess = rotate(stack_b);
	else if (!ft_strncmp("sa", ptr, size))
		sucess = swap(stack_a);
	else if (!ft_strncmp("sb", ptr, size))
		sucess = swap(stack_b);
	else if (!ft_strncmp("pa", ptr, size))
		sucess = push(stack_b, stack_a);
	else if (!ft_strncmp("pb", ptr, size))
		sucess = push(stack_a, stack_b);
	else if (!ft_strncmp("rra", ptr, size))
		sucess = rev_rotate(stack_a);
	if (sucess)
	{
		write (1, ptr, size);
		write (1, "\n", 1);
	}
}
