/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:30:38 by ruida-si          #+#    #+#             */
/*   Updated: 2024/11/30 16:16:44 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		ft_atoi(char *s);
t_node	*ft_last(t_node *node);
int		ft_strlen(char *s);
int		in_order(t_node *node);
void	swap(t_node **a);
void	order_stack(t_node **a, int ac);
int		lst_size(t_node *node);
void	rotate(t_node **a);
void	rev_rotate(t_node **a);

#endif
