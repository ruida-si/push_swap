/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:43:39 by ruida-si          #+#    #+#             */
/*   Updated: 2024/11/30 15:43:42 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stack(t_node **a, t_node **b, int n)
{
	if (n == 2)
		sa(a);
	create_index(a, n);
	if (n == 3)
		order_3(a, 0);
	if (n > 3)
		order_radix(a, b, n);
}

void	order_radix(t_node **a, t_node **b, int n)
{
	int		bit;
	t_node	*node;
	int		i;

	bit = 0;
	while (!in_order(*a))
	{
		i = 0;
		while (i < n)
		{
			node = *a;
			if ((node->index >> bit) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}

int	in_order(t_node *node)
{
	if (!node)
		return (1);
	node = node->next;
	while (node)
	{
		if (node->nbr < node->prev->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

void	order_3(t_node **a, int index)
{
	index = (*a)->index;
	if (index == 0)
	{
		rra(a);
		sa(a);
	}
	if (index == 2)
	{
		ra(a);
		if (!in_order(*a))
			sa(a);
	}
	if (index == 1)
	{
		if ((*a)->nbr > ft_last(*a)->nbr)
			rra(a);
		else
			sa(a);
	}
}
