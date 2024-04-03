/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:48:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/02 00:15:30 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "ft_args.h"
#include "ft_thread.h"
#include "ft_philosopher.h"

//https://github.com/DeRuina/philosophers/blob/main/src/threads.c

void    ft_main_check_simulation(t_table *table)
{
//    table = (void *)table;
		int 		i;
		int 		number_meals;
		t_bool		bn_meals;
		t_bool		b_one_dead;
		t_timestamp	now;
		t_timestamp	last_meal_time;

		i = 0;
		bn_meals = TRUE;
		b_one_dead = FALSE;
		while( (size_t)i < table->philosophers_set.total)
		{
			number_meals = ft_mutex_meal_get_num(&table->philosophers_set.philosophers[i].meals);
			if(table->rules.number_eats > 0 && number_meals < table->rules.number_eats)
				bn_meals = FALSE;
			
			//printf("\t\t %d philosopher has eaten %d times\n",table->philosophers_set.philosophers[i].number, number_meals);
			now = ft_timestamp_get();
			last_meal_time = ft_mutex_meal_get_time(&table->philosophers_set.philosophers[i].meals);
			//printf("\t\t %d philosopher now %llu last_meal %llu start time %llu\n",i + 1 , now - now, now - last_meal_time, now - table->start_time);
			if (now - last_meal_time >= table->rules.time_to_die)
			{
				ft_thread_printf(&table->philosophers_set.philosophers[i], "died", now - table->philosophers_set.philosophers[i].start_time);
				//printf("%llu %d died\n", now - table->start_time, table->philosophers_set.philosophers[i].number);
				b_one_dead = TRUE;
				break;
			}
			i++;
			ft_thread_sleep(500);
		}
		if (table->rules.number_eats > 0 && bn_meals == TRUE)
		{
			ft_mutex_bvalue_set(&table->end, TRUE);
			return ;
		}
		if (b_one_dead == TRUE)
			ft_mutex_bvalue_set(&table->end, TRUE);
}


void    ft_main_run_simulation(t_table *table)
{
	while (ft_mutex_bvalue_get(&table->end) == FALSE)
	{
		ft_main_check_simulation(table);
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
 
	if (ft_args_validate_format(argv, argc) == FALSE)
		return (EXIT_FAILURE);
	args    = ft_args_parse(argv, argc);
	if (ft_args_validate_value(args) == FALSE)
		return (EXIT_FAILURE);
	table   = ft_table_init(args);
	if (ft_main_check_init(&table) == -1)
		return (1);
	ft_thread_create_threads(&table);
	ft_main_run_simulation(&table);
	ft_thread_join_threads(&table.philosophers_set);
	ft_table_destroy(&table);
	//ft_philosophers_destroy(&table.philosophers_set);
	printf("FINITO\n");
	return (0);
}