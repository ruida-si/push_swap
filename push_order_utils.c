/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:52:41 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/14 15:13:05 by ruida-si         ###   ########.fr       */
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

void	put_ontop(t_node **a, int n)
{
	t_node	*node;
	int		i;
	int		med;

	med = find_med(n);
	i = 0;
	node = *a;
	while (node)
	{
		if (node->index == 0)
			break ;
		i++;
		node = node->next;
	}
	if (i < med)
	{
		while (i-- > 0)
			ra(a);
	}
	else
	{
		while (i++ < n)
			rra(a);
	}
}

int	find_med(int n)
{
	int	med;

	if (n % 2 != 0)
		med = n / 2 + 1;
	else
		med = n / 2;
	return (med);
}

void	reset_index(t_node **a, int n)
{
	t_node	*node;

	node = *a;
	while (node)
	{
		node->order = 0;
		node = node->next;
	}
	create_index(a, n);
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
