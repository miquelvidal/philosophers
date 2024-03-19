/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:19:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/19 22:32:15 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THREADS_H
# define FT_THREADS_H

# include "ft_philosopher.h"

int	ft_thread_sleep(int milliseconds);
int ft_thread_create_threads(t_philosopher *philo, size_t num_philo);
int	ft_thread_join_threads(t_philosopher *philo, size_t num_philo);

#endif