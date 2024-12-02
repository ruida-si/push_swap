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

void	order_stack(t_node **a, int n)
{
	if (n == 2)
		sa(a);
	if (n == 3)
		order_3(a, 0);
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
	index = find_min(*a);
	if (index == 0)
	{
		rra(a);
		sa(a);
	}
	if (index == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
		rra(a);
	}
	if (index == 1)
	{
		if ((*a)->nbr > ft_last(*a)->nbr)
			ra(a);
		else
			sa(a);
	}
}

int	find_min(t_node *node)
{
	int	min;
	int	index;

	min = node->nbr;
	while (node)
	{
		if (node->nbr <= min)
		{
			index = node->index;
			min = node->nbr;
		}
		node = node->next;
	}
	return (index);
}
