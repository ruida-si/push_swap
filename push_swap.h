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
	int				index;
	int				order;
	char			*binary;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// functions for lists
t_node	*ft_last(t_node *node);
int		lst_size(t_node *node);

// basic utils
int		ft_atoi(char *s);
int		ft_strlen(char *s);
void	putstr(char *s);
void	fill_zero(char *s);

char	*create_binary(int n);
void	print_binary(t_node **a);

// order stack functions
int		find_min(t_node *node);
int		in_order(t_node *node);
void	order_stack(t_node **a, int n);
void	order_3(t_node **a, int index);
void	order_radix(t_node **a, int n);
void	find_low(t_node **a, int n);

// operations with stacks
int		swap(t_node **a);
int		rotate(t_node **a);
int		rev_rotate(t_node **a);
int		push(t_node **a, t_node **b);

// SWAP FUNCTIONS
void	sa(t_node **a);
void	sb(t_node **a);
void	ss(t_node **a, t_node **b);

// REV ROTATE FUNCTIONS
void	rra(t_node **a);
void	rrb(t_node **a);
void	rrr(t_node **a, t_node **b);

// ROTATE FUNCTIONS
void	ra(t_node **a);
void	rb(t_node **a);
void	rr(t_node **a, t_node **b);

// PUSH FUNCTIONS
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);

// FILL STACK
int		fill_numb(int ac, char **av, t_node **a, int i);
void	free_stack(t_node *node);

// SPLIT FUNCTIONS
void	free_mem(char **av, int i);
int		length(char *s);
char	**fill_split(char **av, char *s);
int		app_split(char *s, char **av, int count, t_node **a);
int		count_wd(char *s);

#endif
