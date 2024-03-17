/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:03:25 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/17 01:19:10 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILOSOPHER_H
# define FT_PHILOSOPHER_H

# include <stddef.h>
# include <pthread.h>

# define PHILO_STATUS_EAT   1
# define PHILO_STATUS_THINK 2
# define PHILO_STATUS_SLEEP 3

# define NO_FORK -1;

typedef struct s_philosopher
{
	size_t          number;
	unsigned int	status;
	int				left_fork;
	int				right_fork;
	pthread_t       thread;
}   t_philosopher;

#endif