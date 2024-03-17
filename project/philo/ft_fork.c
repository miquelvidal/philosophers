/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:33:37 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/17 23:48:35 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fork.h"

t_fork	ft_fork_new(size_t num)
{
	t_fork	fork;

	fork.num_fork = num;
	return (fork);
}

t_fork	*ft_fork_init(size_t total)
{
	size_t	i;
	t_fork	*forks;

	forks = (t_fork *)malloc(total * sizeof(t_fork));
	if (forks == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		forks[i] = ft_fork_new(i);
	}
	return (forks);
}

void	ft_fork_destroy(t_fork * forks)
{
	if (forks != NULL)
		free (forks);
}
