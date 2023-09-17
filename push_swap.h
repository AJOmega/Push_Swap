/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:25:31 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/16 19:41:24 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list	t_list;

struct	s_list
{
	int		data;
	int		index;
	t_list	*next;
};

// main.c

void	print_error(char *msg, t_list **head);
void	atoi_list(char *str, t_list **head);
void	check_arguments(int argc, char*argv[]);

// list_utils.c

void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	free_list(t_list **head);

// utils.c

size_t	ft_strlen(const char *str);

// list_checker.c

void	check_list(t_list **list);
void	check_duplicates(t_list **list);
void	check_order(t_list **list);

#endif
