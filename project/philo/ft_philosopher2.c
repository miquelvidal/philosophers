/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:25:18 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/03 20:24:57 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_thread.h"
#include "ft_args.h"
#include "ft_philosopher.h"
#include "ft_timestamp.h"
#include "ft_sleep.h"

void	*ft_philosopher_life(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (ft_mutex_bvalue_get(&philo->end) == FALSE)
	{
		if (philo->status == PHILO_STATUS_INIT || \
				philo->status == PHILO_STATUS_THINK)
		{
			ft_philosopher_eat(philo);
			continue ;
		}
		if (philo->status == PHILO_STATUS_EAT)
		{
			ft_philosopher_sleep(philo);
			continue ;
		}
		if (philo->status == PHILO_STATUS_SLEEP)
		{
			ft_philosopher_think(philo);
			continue ;
		}
	}
	if (philo->status  == PHILO_STATUS_EAT)
	{
		ft_fork_drop(philo->l_fork);
		ft_fork_drop(philo->r_fork);
	}

	return (NULL);
}

void	ft_philosopher_eat(t_philosopher *philo)
{
	t_timestamp	timestamp;

	philo->status = PHILO_STATUS_EAT;
	ft_fork_pickup(philo->l_fork);
	timestamp = ft_timestamp_get();
	ft_thread_printf(philo, "has taken a fork", timestamp - philo->start_time);
	if (philo->total == 1)
	{
		ft_sleep(philo->rules.time_to_die);
		ft_fork_drop(philo->l_fork);
		return ;
	}
	ft_fork_pickup(philo->r_fork);
	if (ft_mutex_bvalue_get(&philo->end) == FALSE)
	{
		timestamp = ft_timestamp_get();
		ft_thread_printf(philo, "has taken a fork", timestamp - philo->start_time);
	}
	if (ft_mutex_bvalue_get(&philo->end) == FALSE)
	{
		timestamp = ft_timestamp_get();
		ft_mutex_meal_update(&philo->meals, timestamp);
		ft_thread_printf(philo, "is eating", timestamp - philo->start_time);
	}
	ft_sleep(philo->rules.time_to_eat);
}

void	ft_philosopher_sleep(t_philosopher *philo)
{
	t_timestamp	timestamp;

	ft_fork_drop(philo->r_fork);
	ft_fork_drop(philo->l_fork);
	if (ft_mutex_bvalue_get(&philo->end) == FALSE)
	//{
//	pthread_mutex_lock(&philo->end->mutex);
	//if (philo->end->value == FALSE)
	{
		philo->status = PHILO_STATUS_SLEEP;
		timestamp = ft_timestamp_get();
		ft_thread_printf(philo, "is sleeping", timestamp - philo->start_time);
	}
//	pthread_mutex_unlock(&philo->end->mutex);
	ft_sleep(philo->rules.time_to_sleep);
}

void	ft_philosopher_think(t_philosopher *philo)
{
	t_timestamp	timestamp;

	if (ft_mutex_bvalue_get(&philo->end) == FALSE)
	//{
		//pthread_mutex_lock(&philo->end->mutex);
		//if (philo->end->value == FALSE)
		{
			philo->status = PHILO_STATUS_THINK;
			timestamp = ft_timestamp_get();
			ft_thread_printf(philo, "is thinking", timestamp - philo->start_time);
		}
		//pthread_mutex_unlock(&philo->end->mutex);
	//}
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
