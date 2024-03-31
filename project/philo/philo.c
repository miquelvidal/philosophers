/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:48:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/31 00:36:12 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "ft_args.h"
#include "ft_thread.h"
#include "ft_philosopher.h"


void    ft_main_run_simulation(t_table *table)
{
    while (ft_mutex_bvalue_get(&table->end) == FALSE)
    {
        
    }
}

int main(int argc, char **argv)
{
    t_args          args;
    t_table         table;
 
    if (ft_args_validate(argv, argc) == FALSE)
        return (EXIT_FAILURE);
    args    = ft_args_parse(argv, argc);
    table   = ft_table_init(args);
    ft_thread_create_threads(&table);
    ft_main_run_simulation(&table);
    ft_thread_join_threads(&table.philosophers_set);
    ft_philosophers_destroy(&table.philosophers_set);
    printf("FINITO\n");
    exit (EXIT_SUCCESS);
}