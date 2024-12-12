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
