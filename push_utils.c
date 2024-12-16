/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:26:48 by ruida-si          #+#    #+#             */
/*   Updated: 2024/11/30 15:44:02 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (ft_strlen(s) > 11)
		return (0);
	if ((s[0] == '-' && s[1] == '0') || (s[0] == '0' && s[1] != '\0'))
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

void	putstr(char *s)
{
	int	n;

	n = ft_strlen(s);
	write (1, s, n);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_node	*ft_last(t_node *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}

int	lst_size(t_node *node)
{
	int	i;

	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}
