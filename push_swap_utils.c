/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:26:48 by ruida-si          #+#    #+#             */
/*   Updated: 2024/11/29 16:26:54 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(char *s)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (ft_strlen(s) > 11)
		return (0);
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	n *= sign;
	if (*s || n > INT_MAX || n < INT_MIN)
		return (0);
	return (n);
}

t_node	*ft_last(t_node *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}
