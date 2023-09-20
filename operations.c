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

	size = ft_strlen(ptr);
	if (ptr[0] == 'r')
		sucess = exec_rotate(ptr, stack_a, stack_b, size);
}