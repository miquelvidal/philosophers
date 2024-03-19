/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:48:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/19 23:08:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "ft_args.h"
#include "ft_thread.h"
#include "ft_philosopher.h"

int main(int argc, char **argv)
{
    t_args          args;
    t_philosopher   *philo;

    if (ft_args_validate(argv, argc) == FALSE)
        return (EXIT_FAILURE);
    args = ft_args_parse(argv, argc);
    philo = ft_philosopher_init(args);
    ft_thread_create_threads(philo, args.num_philo);
    ft_thread_join_threads(philo, args.num_philo);
    ft_philosopher_destroy(philo, args.num_philo);
    printf("FINITO\n");
    return (EXIT_SUCCESS);
}