/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:48:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/17 23:06:12 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "ft_args.h"

int main(int argc, char **argv)
{
    t_args args;

    if (ft_args_validate(argv, argc) == FALSE)
        return (EXIT_FAILURE);
    args = ft_args_parse(argv, argc); 
    args.num_must_eat++;   
    return (EXIT_SUCCESS);
}