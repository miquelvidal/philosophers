/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:03:25 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/30 18:30:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILOSOPHER_H
# define FT_PHILOSOPHER_H

# include <stddef.h>
# include <pthread.h>

# include "ft_args.h"
# include "ft_fork.h"

# define PHILO_STATUS_INIT -1
# define PHILO_STATUS_EAT   1
# define PHILO_STATUS_THINK 2
# define PHILO_STATUS_SLEEP 3

typedef struct s_philosopher
{
	size_t          number;
	unsigned int	status;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t       thread;
	t_bool			*end;
	t_bool			*start;
}   t_philosopher;

typedef struct s_philosopher_set
{
	size_t  total;
	t_philosopher   *philosophers;
}   t_philosopher_set;

t_philosopher_set  ft_philosophers_init(t_args args);
t_philosopher	ft_philosopher_new(size_t num_philo);
void            ft_philosopher_free(t_philosopher *philosopher);
void            ft_philosophers_destroy(t_philosopher_set *philosophers);
void			*ft_philosopher_execute(void *arg);

#endif