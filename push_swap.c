/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:30:44 by ruida-si          #+#    #+#             */
/*   Updated: 2024/11/30 16:16:24 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node(int n, t_node **a, t_node *last, t_node *new)
{
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->nbr = n;
	new->next = NULL;
	if (!*a)
	{
		new->prev = NULL;
		*a = new;
	}
	else
	{
		last = ft_last(*a);
		new->prev = last;
		last->next = new;
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
		if ((n == 0 && !(av[i][0] == '0' && !av[i][1])) ||
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
	if (ac < 3 || !fill_numb(ac, av, &a))
		return (1);
	if (!in_order(a))
		order_stack(&a, ac -1);
	int n = a->nbr;
	printf("%i\n", n);
	return (0);
}
