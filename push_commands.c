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

void	rr(t_node **a, t_node **b)
{
	if (rotate(a) && rotate(b))
		putstr("rr\n");
}

int	swap(t_node **a)
{
	t_node	*temp;
	t_node	*prox;
	t_node	*third;

	if (!a || lst_size(*a) < 2)
		return (0);
	temp = *a;
	prox = temp->next;
	third = prox->next;
	*a = prox;
	prox->next = temp;
	prox->prev = NULL;
	temp->prev = prox;
	temp->next = third;
	if (third)
		third->prev = temp;
	return (1);
}

int	rotate(t_node **a)
{
	t_node	*first;
	t_node	*last;

	last = ft_last(*a);
	first = *a;
	if (!a || lst_size(*a) < 2)
		return (0);
	*a = first->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	return (1);
}

int	rev_rotate(t_node **a)
{
	t_node	*first;
	t_node	*last;
	t_node	*end;

	last = ft_last(*a);
	end = last->prev;
	first = *a;
	if (!a || lst_size(*a) < 2)
		return (0);
	*a = last;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	end->next = NULL;
	return (1);
}

int	push(t_node **a, t_node **b)
{
	t_node	*tempb;

	if (!*b)
		return (0);
	tempb = (*b)->next;
	if (tempb)
		tempb->prev = NULL;
	(*b)->next = *a;
	if (*a)
		(*a)->prev = *b;
	*a = *b;
	*b = tempb;
	return (1);
}
