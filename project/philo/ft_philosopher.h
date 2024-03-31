/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:03:25 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/01 00:40:26 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILOSOPHER_H
# define FT_PHILOSOPHER_H

# include <stddef.h>
# include <pthread.h>

# include "ft_args.h"
# include "ft_rules.h"
# include "ft_fork.h"
# include "ft_mutex_bflag.h"
# include "ft_mutex_meal.h"

# define PHILO_STATUS_INIT -1
# define PHILO_STATUS_EAT   1
# define PHILO_STATUS_THINK 2
# define PHILO_STATUS_SLEEP 3

typedef struct s_philosopher
{
	int          	number;
	int				status;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t       thread;
	t_mutex_bflag	*end;
	t_mutex_meal	meals;
	t_rules			rules;
	t_bool			*start;

}   t_philosopher;

typedef struct s_philosopher_set
{
	size_t  total;
	t_philosopher   *philosophers;
}   t_philosopher_set;

t_philosopher_set	ft_philosophers_init(t_args args, t_fork_set forks);
t_philosopher		ft_philosopher_new(size_t num_philo);
void            	ft_philosopher_free(t_philosopher *philosopher);
void            	ft_philosophers_destroy(t_philosopher_set *philosophers);
void				*ft_philosopher_execute(void *arg);
void				ft_philosopher_eat(t_philosopher *philo);
void				ft_philosopher_sleep(t_philosopher *philo);
void				ft_philosopher_think(t_philosopher *philo);
#endif