/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:56:40 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/10 15:56:45 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **a, t_node **b)
{
	if (push(b, a))
		putstr("pb\n");
}

void	pa(t_node **a, t_node **b)
{
	if (push(a, b))
		putstr("pa\n");
}

void	rra(t_node **a)
{
	if (rev_rotate(a))
		putstr("rra\n");
}

void	rrb(t_node **a)
{
	if (rev_rotate(a))
		putstr("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	if (rev_rotate(a) && rev_rotate(b))
		putstr("rrr\n");
}
