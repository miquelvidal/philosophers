/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:19:28 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/19 23:21:37 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include "ft_philosopher.h"

#include <stdio.h>
//https://man7.org/linux/man-pages/man3/pthread_create.3.html

int	ft_thread_sleep(int milliseconds)
{
		return (usleep(milliseconds));    
}

int ft_thread_create_threads(t_philosopher *philo, size_t num_philo)
{
	size_t		i;
	pthread_t	thread_id;

	i = 0;
	printf("Create thread num: %lu\n", num_philo);
	while (i < num_philo)
	{
		pthread_create(&thread_id, NULL, ft_philosopher_execute, philo + i);
		philo[i].thread = thread_id;
		//pthread_detach(philo[i].thread);
		i++;
	}
	return (0);
}

int	ft_thread_join_threads(t_philosopher *philo, size_t num_philo)
{
	size_t	i;

	i = 0;
	while(i < num_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (0);
}