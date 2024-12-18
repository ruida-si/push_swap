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
	if (swap(a))
		putstr("sa\n");
}

void	sb(t_node **a)
{
	if (swap(a))
		putstr("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	if (swap(a) && swap(b))
		putstr("ss\n");
}

void	ra(t_node **a)
{
	if (rotate(a))
		putstr("ra\n");
}

void	rb(t_node **a)
{
	if (rotate(a))
		putstr("rb\n");
}
