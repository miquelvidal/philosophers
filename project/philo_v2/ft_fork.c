/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:33:37 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/02 23:04:03 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_fork.h"
#include "ft_timestamp.h"

t_fork	ft_fork_new(size_t num)
{
	t_fork	fork;

	fork.num_fork = num;
	pthread_mutex_init(&fork.mutex, NULL);
	return (fork);
}

t_fork_set	ft_forks_init(size_t total)
{
	size_t		i;
	t_fork_set	_forks;

	_forks.forks = (t_fork *)malloc(total * sizeof(t_fork));
	if (_forks.forks == NULL)
	{
		_forks.forks = 0;
		return (_forks);
	}
	i = 0;
	while (i < total)
	{
		_forks.forks[i] = ft_fork_new(i);
		i++;
	}
	_forks.num_forks = total;
	return (_forks);
}

void	ft_forks_destroy(t_fork_set *_forks)
{
	size_t	i;

	if (_forks->forks != NULL)
	{
		i = 0;
		while (i < _forks->num_forks)
		{
//            printf("UNLOCKING\n");
//            pthread_mutex_unlock(&_forks->forks[i].mutex);
			pthread_mutex_destroy(&_forks->forks[i].mutex);
			i++;
		}
		free (_forks->forks);
		_forks->forks = NULL;
		_forks->num_forks = 0;
	}
}

int	ft_fork_pickup(t_fork *fork)
{
	int	mutex_return;

	if (fork != NULL)
	{
		mutex_return = pthread_mutex_lock(&fork->mutex);
		return (mutex_return);
	}
	return (0);
}

int	ft_fork_drop(t_fork *fork)
{
	int	mutex_return;

	if (fork != NULL)
	{
		mutex_return = pthread_mutex_unlock(&fork->mutex);
		return (mutex_return);
	}
	return (0);
}
