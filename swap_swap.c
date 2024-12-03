/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:28:55 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/02 15:28:59 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	swap(a);
	putstr("sa\n");
}

void	sb(t_node **a)
{
	swap(a);
	putstr("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	putstr("ss\n");
}

void	rra(t_node **a)
{
	rev_rotate(a);
	putstr("rra\n");
}

void	rrb(t_node **a)
{
	rev_rotate(a);
	putstr("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	putstr("rrr\n");
}

void	ra(t_node **a)
{
	rotate(a);
	putstr("ra\n");
}

void	rb(t_node **a)
{
	rotate(a);
	putstr("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	putstr("rr\n");
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	putstr("pb\n");
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	putstr("pa\n");
}
