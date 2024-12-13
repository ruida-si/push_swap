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
		order_3(a);
	if (n == 4)
		order_4(a, b);
	else
		order_radix(a, b, n);
}

void	order_4(t_node **a, t_node **b)
{
	t_node	*node;
	int		i;

	node = *a;
	i = 0;
	while (node)
	{
		if (node->index == 0)
			break ;
		i++;
		node = node->next;
	}
	if (i < 2)
	{
		while (i-- > 0)
			ra(a);
	}
	else
	{
		while (i++ < 4)
			rra(a);		
	}
	pb(a, b);
	reset_index(a);
	if (!in_order(*a))
		order_3(a);
	pa(a, b);
}

void	reset_index(t_node **a)
{
	t_node	*node;

	node = *a;
	while (node)
	{
		node->order = 0;
		node = node->next;
	}
	create_index(a, 3);
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
