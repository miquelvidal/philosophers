/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:48:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/01 00:49:43 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "ft_args.h"
#include "ft_thread.h"
#include "ft_philosopher.h"


void    ft_main_check_simulation(t_table *table)
{
    table = (void *)table;
}

void    ft_main_run_simulation(t_table *table)
{
    while (ft_mutex_bvalue_get(&table->end) == FALSE)
    {
        
    }
}

int     ft_main_check_init(t_table *table)
{
    if (table->philosophers_set.philosophers == NULL || table->forks_set.forks == NULL)
    {
        ft_table_destroy(table);
        /*
        if (table.philosophers_set.philosophers != NULL)
            free (table.philosophers_set.philosophers);
        if (table.forks_set.forks != NULL)
            free (table.forks_set.forks);
            */
        return (-1);
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_args          args;
    t_table         table;
 
    if (ft_args_validate(argv, argc) == FALSE)
        return (EXIT_FAILURE);
    args    = ft_args_parse(argv, argc);
    table   = ft_table_init(args);
    if (ft_main_check_init(&table) == -1)
        return (1);
    ft_thread_create_threads(&table);
    ft_main_run_simulation(&table);
    ft_thread_join_threads(&table.philosophers_set);
    ft_philosophers_destroy(&table.philosophers_set);
    printf("FINITO\n");
    return (0);
}