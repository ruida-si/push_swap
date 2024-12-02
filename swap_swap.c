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

void	rra(t_node **a)
{
	rev_rotate(a);
	putstr("rra\n");
}

void	ra(t_node **a)
{
	rotate(a);
	putstr("ra\n");
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	putstr("pb\n");
}
