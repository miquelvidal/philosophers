/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:25:18 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/01 00:41:19 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_args.h"
#include "ft_philosopher.h"
#include "ft_timestamp.h"
#include "ft_sleep.h"

t_philosopher	ft_philosopher_new(size_t num_philo)
{
	t_philosopher	philosopher;

	philosopher.number				= num_philo + 1;
	philosopher.status 				= PHILO_STATUS_INIT;
	philosopher.l_fork				= NULL;
	philosopher.r_fork				= NULL;
	philosopher.meals.num_meals 	= 0;
	philosopher.meals.timestamp 	= 0l;
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
		ft_mutex_meal_init(&philo.philosophers[i].meals);
		philo.philosophers[i].rules.number_eats		= args.num_must_eat;
		philo.philosophers[i].rules.time_to_die		= args.time_to_die;
		philo.philosophers[i].rules.time_to_eat 	= args.time_to_eat;
		philo.philosophers[i].rules.time_to_sleep	= args.time_to_sleep;
		if (i == philo.total -1 )
		{
			philo.philosophers[i].l_fork = &forks.forks[i];
			philo.philosophers[i].r_fork = &forks.forks[0];
		}
		else
		{
			philo.philosophers[i].l_fork = &forks.forks[i];
			if (i + 1 < philo.total)
				philo.philosophers[i].r_fork = &forks.forks[i + 1];
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
	while (ft_mutex_bvalue_get(philo->end) == FALSE)
	{
		if (philo->status == PHILO_STATUS_INIT || philo->status == PHILO_STATUS_THINK)
		{
			ft_philosopher_eat(philo);
			continue;
		}
		if (philo->status == PHILO_STATUS_EAT)
		{
			ft_philosopher_sleep(philo);
			continue;
		}
		if (philo->status == PHILO_STATUS_SLEEP)
		{
			ft_philosopher_think(philo);
			continue;
		}
	}
	return (NULL);
}

void	ft_philosopher_eat(t_philosopher *philo)
{
	t_timestamp	timestamp;

	philo->status = PHILO_STATUS_EAT;
	ft_fork_pickup(philo->l_fork);
	timestamp = ft_timestamp_get();
	printf("%llu %d has taken a fork\n", timestamp, philo->number);
	ft_fork_pickup(philo->r_fork);
	timestamp = ft_timestamp_get();
	printf("%llu %d has taken a fork\n", timestamp, philo->number);
	timestamp = ft_timestamp_get();
	printf("%llu %d is eating\n",timestamp, philo->number);
	ft_sleep(philo->rules.time_to_eat);
	ft_mutex_meal_update(&philo->meals, timestamp);
	ft_fork_drop(philo->r_fork);
	ft_fork_drop(philo->l_fork);
}

void	ft_philosopher_sleep(t_philosopher *philo)
{
	t_timestamp	timestamp;
	
	philo->status = PHILO_STATUS_SLEEP;
	timestamp = ft_timestamp_get();
	printf("%llu %d is sleeping\n", timestamp, philo->number);
	ft_sleep(philo->rules.time_to_sleep);
}

void	ft_philosopher_think(t_philosopher *philo)
{
	t_timestamp	timestamp;
	
	philo->status = PHILO_STATUS_THINK;
	timestamp = ft_timestamp_get();
	printf("%llu %d is thinking\n", timestamp, philo->number);
	//ft_sleep(philo->rules.time_to);
}
/*
void	ft_philosopher_die(t_philosopher *philo)
{
	t_timestamp	timestamp;
	
	timestamp = ft_timestamp_get();
	printf("%llu %d died\n", timestamp, philo->number);
	ft_mutex_bvalue_set(philo->end, TRUE);
	//ft_sleep(philo->rules.time_to);
}
*/
