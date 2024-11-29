/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sawp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:30:44 by ruida-si          #+#    #+#             */
/*   Updated: 2024/11/27 17:30:46 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node(int n, t_node **a, t_node *last, t_node *new)
{
	t_node	*lst;

	lst = *a;
	new = malloc(sizeof(t_node) + 1);
	if (!new)
		return ;
	if (!lst)
	{
		new->nbr = n;
		new->prev = NULL;
		new->next = NULL;
		lst = new;
	}
	else
	{
		last = ft_last(lst);
		new->nbr = n;
		new->prev = last;
		new->next = NULL;
	}
}

int	have_dup(int n, t_node *current)
{
	while (current)
	{
		if (current->nbr == n)
			return (1);
		current = current->next;
	}
	return (0);
}

int	fill_numb(int ac, char **av, t_node **a)
{
	int	i;
	int	n;

	i = 1;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if ((n == 0 && av[i][0] != '0') ||
		have_dup(n, *a))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		create_node(n, a, NULL, NULL);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 3)
		return (1);
	if (!fill_numb(ac, av, &a))
		return (1);
}
