/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:08:35 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/20 22:04:41 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Add a node After Last Node

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

// Add Content inside The last Node

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->data = content;
	new->next = NULL;
	return (new);
}

void	free_list(t_list **head)
{
	t_list	*temp;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	exit(0);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp_lst;

	i = 0;
	temp_lst = lst;
	while (temp_lst)
	{
		temp_lst = temp_lst->next;
		i++;
	}
	return (i);
}
