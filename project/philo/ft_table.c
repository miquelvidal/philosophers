/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:53:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/01 17:01:51 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "ft_table.h"
#include "ft_args.h"

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
    pthread_mutex_destroy(&table->end.mutex);
    /*
    if (table->rules != NULL)
        ft_rules_destroy(table->rules);
    */
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

t_table ft_table_init(t_args args)
{
    t_table table;
    table.rules = ft_rules_init(args);
    //if (table.rules == NULL)
     //   return (table);
    table.forks_set = ft_forks_init(args.num_philo);
    table.philosophers_set = ft_philosophers_init(args, table.forks_set, table.rules);   
    table.end = ft_mutex_bvalue_init(FALSE);
    return (table);
}
