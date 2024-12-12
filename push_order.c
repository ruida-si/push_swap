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
	if (n < 6)
		order_5(a, b, n);
	else
		order_radix(a, b, n);
}

void	order_5(t_node **a, t_node **b, int n)
{
	if (n == 4)
		pb(a, b);
	else
	{
		pb(a, b);
		pb(a, b);
	}
	order_3(a, 0);
	if (in_order(*b))
		sb(b);
	if (n == 4)
		order_4(a, b);
	else
	{
		if ((*b)->index == 1)
		{
			pa(a, b);
			pa(a, b);
		}
	}
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
