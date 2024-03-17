/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:25:18 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/17 23:48:54 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_philosopher.h"

t_philosopher	ft_philosopher_new(size_t num_philo, t_args args)
{
	t_philosopher	philosopher;

	philosopher.number		= num_philo;
	philosopher.status 		= PHILO_STATUS_INIT;
	philosopher.left_fork	= NULL;
	philosopher.right_fork	= NULL;
	return (philosopher);
}

t_philosopher   *ft_philosopher_init(t_args args)
{
	t_philosopher	*philosophers;
	size_t			i;

	philosophers = (t_philosopher *)malloc(args.num_philo * sizeof(t_philosopher));
	if (philosophers == NULL)
		return (NULL);
	i = 0;
	while (i < args.num_philo)
	{
		philosophers[i] = ft_philosopher_new(i, args);
		i++;
	}
	return (philosophers);
}

void	ft_philosopher_destroy(t_philosopher *philosophers)
{
	if (philosophers != NULL)
		free (philosophers);
}