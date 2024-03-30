/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:25:18 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/30 18:06:05 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_args.h"
#include "ft_philosopher.h"
#include <stdio.h>

t_philosopher	ft_philosopher_new(size_t num_philo)
{
	t_philosopher	philosopher;

	philosopher.number		= num_philo;
	philosopher.status 		= PHILO_STATUS_INIT;
	philosopher.left_fork	= NULL;
	philosopher.right_fork	= NULL;
	return (philosopher);
}

t_philosopher_set   ft_philosophers_init(t_args args)
{
	t_philosopher_set	philo;
	size_t				i;

	philo.philosophers = (t_philosopher *)malloc(args.num_philo * sizeof(t_philosopher));
	if (philo.philosophers == NULL)
		return (philo);
	philo.total = args.num_philo;
	i = 0;
	while (i < args.num_philo)
	{
		philo.philosophers[i] = ft_philosopher_new(i);
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