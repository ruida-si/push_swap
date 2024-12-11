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
	if (n > 3)
		order_radix(a, n);
}

void	order_radix(t_node **a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		find_low(a, i);
		i++;
	}
	print_binary(a);
}

void	print_binary(t_node **a)
{
	t_node	*node;
	int		n;
	char	*s;
	
	node = *a;
	while (node)
	{		
		n = node->index;
		s = create_binary(n);
		node->binary = s;
		node = node->next;
	}
}

char	*create_binary(int n)
{
	char	*array;
	int		index;
	
	array = malloc(33);
	if (!array)
		return (NULL);
	fill_zero(array);
	index = 31;
	while (n > 0)
	{
		array[index] = n % 2 + '0';
		n /= 2;
		index--;
	}
	return (array);
}

void	fill_zero(char *s)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		s[i] = '0';
		i++;
	}
	s[i] = '\0';
}

void	find_low(t_node **a, int n)
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
		}
		node = node->next;
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
