/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:48:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/30 18:45:46 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "ft_args.h"
#include "ft_thread.h"
#include "ft_philosopher.h"


static  void    ft_main_init_table(t_args args, t_table *table)
{
    table->philosophers_set = ft_philosophers_init(args);   
}

int main(int argc, char **argv)
{
    t_args          args;
    t_table         table;
 
    if (ft_args_validate(argv, argc) == FALSE)
        return (EXIT_FAILURE);
    args = ft_args_parse(argv, argc);
    ft_main_init_table(args, &table);
    ft_thread_create_threads(table);
    ft_thread_join_threads(&table.philosophers_set);
    ft_philosophers_destroy(&table.philosophers_set);
    printf("FINITO\n");
    return (EXIT_SUCCESS);
}