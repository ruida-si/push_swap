/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:42:31 by ruida-si          #+#    #+#             */
/*   Updated: 2024/11/30 15:43:27 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_order(t_node *node)
{
	node = node->next;
	while (node)
	{
		if (node->nbr < node->prev->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

void	swap(t_node **a)
{
	t_node	*temp;
	t_node	*prox;

	if (!a || lst_size(*a) < 2)
		return ;
	temp = *a;
	prox = temp->next;
	if (lst_size(*a) == 2)
		temp->next = NULL;
	else
		temp->next = prox->next;
	temp->prev = prox;
	prox->next = temp;
	prox->prev = NULL;
	*a = prox;
}

void	rotate(t_node **a)
{
	t_node	*first;
	t_node	*last;

	last = ft_last(*a);
	first = *a;
	if (!a || lst_size(*a) < 2)
		return ;
	*a = first->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;	
}

void	rev_rotate(t_node **a)
{
	t_node	*first;
	t_node	*last;

	last = ft_last(*a);
	first = *a;
	if (!a || lst_size(*a) < 2)
		return ;
	*a = last;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
}
