/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:47:05 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/16 19:42:41 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *msg, t_list **head)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	free_list(head);
}

void	atoi_list(char *str, t_list **head)
{
	long long	sign;
	long long	number;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == 0)
		return ;
	sign = (*str != '-') - (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	number = 0;
	if (*str == 0)
		print_error("Error", head);
	while (*str >= '0' && *str <= '9')
		number = (number * 10) + (*str++ - '0');
	if (number > INT_MAX || number < INT_MIN)
		print_error("Error", head);
	ft_lstadd_back(head, ft_lstnew(number * sign));
	if ((*str == ' ' || *str == '\t'))
		atoi_list(str, head);
	else if (*str)
		print_error("Error", head);
}

void	check_arguments(int argc, char *argv[])
{
	int	p;
	int	i;
	int	not_empty;

	p = 1;
	not_empty = 0;
	while (p < argc)
	{
		i = 0;
		while (argv[p][i])
		{
			if (argv[p][i] != ' ' && argv[p][i] != '\t')
				not_empty = 1;
			i++;
		}
		p++;
	}
	if (!not_empty || argc < 2)
	{
		write(1, "\n", 1);
		exit (0);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		i;

	check_arguments(argc, argv);
	i = 1;
	a = NULL;
	b = NULL;
	while (i < argc)
		atoi_list(argv[i++], &a);
	check_list(&a);
	start_sorting(&a, &b);
	free_list(&a);
}
