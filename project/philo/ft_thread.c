/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:19:28 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/30 18:44:57 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include "ft_philosopher.h"
#include "ft_table.h"

#include <stdio.h>
//https://man7.org/linux/man-pages/man3/pthread_create.3.html

int	ft_thread_sleep(int milliseconds)
{
		return (usleep(milliseconds));    
}

//int ft_thread_create_threads(t_philosopher_set *philo)
int ft_thread_create_threads(t_table *table)
{
	size_t		i;
	pthread_t	thread_id;

	i = 0;
//	printf("Create thread num: %lu\n", tablphilo->total);
	while (i < table->philosophers_set.total)
	{
//        philo->philosophers[i].run = 
		table->philosophers_set.philosophers[i].end = &table->end;
		table->philosophers_set.philosophers[i].start = &table->start;
		pthread_create(&thread_id, NULL, ft_philosopher_execute, \
				table->philosophers_set.philosophers + i);
		table->philosophers_set.philosophers[i].thread = thread_id;
		//pthread_detach(philo[i].thread);
		i++;
	}

	return (0);
}

int	ft_thread_join_threads(t_philosopher_set *philo)
{
	size_t	i;

	i = 0;
	while(i < philo->total)
	{
		pthread_join(philo->philosophers[i].thread, NULL);
		i++;
	}
	return (0);
}