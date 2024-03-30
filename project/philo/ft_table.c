/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:53:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/30 18:43:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_table.h"
#include <pthread.h>

void	ft_table_destroy(t_table *table)
{
	if (table->forks_set.forks != NULL)
	{
		ft_forks_destroy(&table->forks_set);
	}
	if (table->philosophers_set.philosophers != NULL)
	{
		ft_philosophers_destroy(&table->philosophers_set);
	}
}

t_bool  ft_table_pickup_forks(t_table *table, int num_philosopher)
{
    /*
    pthread_mutex_lock(&table->forks->mutex);
    num_philosopher++;
    pthread_mutex_unlock(&table->forks->mutex);
    return (TRUE);
    */
   (void) table;
   num_philosopher++;
    return (TRUE);
}

