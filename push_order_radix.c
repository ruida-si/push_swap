/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order_radix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:52:41 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/12 12:52:45 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_index(t_node **a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		find_min(a, i);
		i++;
	}
}

void	order_4(t_node **a, t_node **b)
{
	if ((*b)->index == 0)
		pa(a, b);
	if ((*b)->index == 3)
	{
		pa(a, b);
		ra(a);
	}
	if ((*b)->index == 1)
	{
		ra(a);
		pa(a, b);
		rra(a);
	}
	if ((*b)->index == 2)
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
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

void	find_min(t_node **a, int n)
{
	t_node	*node;
	int		min;

	node = *a;
	min = INT_MAX;
	while (node)
	{
		if (node->nbr <= min && node->order == 0)
		{
			min = node->nbr;
		}
		node = node->next;
	}
	node = *a;
	while (node)
	{
		if (node->nbr == min)
		{
			node->order = 1;
			node->index = n;
			return ;
		}
		node = node->next;
	}
}
