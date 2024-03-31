/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:25:18 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/31 03:17:34 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_args.h"
#include "ft_philosopher.h"
#include <stdio.h>

t_philosopher	ft_philosopher_new(size_t num_philo)
{
	t_philosopher	philosopher;

	philosopher.number		= num_philo + 1;
	philosopher.status 		= PHILO_STATUS_INIT;
	philosopher.left_fork	= NULL;
	philosopher.right_fork	= NULL;
	return (philosopher);
}

t_philosopher_set   ft_philosophers_init(t_args args, t_fork_set forks)
{
	t_philosopher_set	philo;
	size_t				i;

	philo.philosophers = (t_philosopher *)malloc(args.num_philo * sizeof(t_philosopher));
	if (philo.philosophers == NULL)
		return (philo);
	philo.total = args.num_philo;
	i = 0;
	while (i < philo.total)
	{
		philo.philosophers[i] = ft_philosopher_new(i);
		/*
		if (i == 0)
		{
			philo.philosophers[i].left_fork = &forks.forks[forks.num_forks - 1];
			philo.philosophers[i].right_fork = &forks.forks[i];
			continue;
		}
		if (i == philo.total - 1)
		{
			philo.philosophers[i].left_fork = &forks.forks[i];
			philo.philosophers[i].right_fork = &forks.forks[0];
			continue;
		}
		philo.philosophers[i].left_fork = &forks.forks[i];
		philo.philosophers[i].right_fork = &forks.forks[0];
		*/
		if (i == philo.total -1 )
		{
			philo.philosophers[i].left_fork = &forks.forks[i];
			philo.philosophers[i].right_fork = &forks.forks[0];
		}
		else
		{
			philo.philosophers[i].left_fork = &forks.forks[i];
			if(i + 1 < philo.total )
				philo.philosophers[i].right_fork = &forks.forks[i + 1];
		}
		i++;
	}
	return (philo);
}

void	ft_philosopher_free(t_philosopher *philosophers)
{
//	if (philosophers != NULL)
//		free (philosophers);
	philosophers++;
}

void	ft_philosophers_destroy(t_philosopher_set *philo)
{
	size_t	i;

	if ( philo->philosophers != NULL)
	{
		i = 0;
		while (i < philo->total)
		{
			ft_philosopher_free(philo->philosophers + i);
			i++;
		}
		free (philo->philosophers);
		philo->philosophers = NULL;
	}
}

void	*ft_philosopher_execute(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	printf("Hola! soy el thread %lu\n", philo->thread);
	return (NULL);
}