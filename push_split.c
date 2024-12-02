/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:30:03 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/02 15:30:07 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	app_split(char *s, char **av, int count, t_node **a)
{
	count = count_wd(s);
	if (count < 2)
		return (0);
	av = malloc(sizeof(char *) * (count +1));
	if (!av)
		return (0);
	if (!fill_split(av, s))
		return (0);
	if (!fill_numb(count, av, a, 0))
	{
		free_mem(av, count -1);
		return (0);
	}
	free_mem(av, count -1);
	return (1);
}

char	**fill_split(char **av, char *s)
{
	int	i;
	int	j;

	i = 0;
	while (*s)
	{
		while (*s < 33 && *s)
			s++;
		if (!*s)
			break ;
		av[i] = malloc(length(s) + 1);
		if (!av[i])
		{
			free_mem(av, i -1);
			return (NULL);
		}
		j = 0;
		while (*s > 32)
			av[i][j++] = *s++;
		av[i][j] = '\0';
		i++;
	}
	av[i] = NULL;
	return (av);
}

int	count_wd(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s < 33 && *s)
			s++;
		if (!*s)
			break ;
		count++;
		while (*s > 32)
			s++;
	}
	return (count);
}

int	length(char *s)
{
	int	i;

	i = 0;
	while (*s > 32)
	{
		i++;
		s++;
	}
	return (i);
}

void	free_mem(char **av, int i)
{
	while (i >= 0)
	{
		free(av[i]);
		i--;
	}
	free(av);
}
