/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:19:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/30 18:20:35 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THREADS_H
# define FT_THREADS_H

# include "ft_philosopher.h"
# include "ft_table.h"

int	ft_thread_sleep(int milliseconds);
//int ft_thread_create_threads(t_philosopher_set *philo);
int ft_thread_create_threads(t_table table);
int	ft_thread_join_threads(t_philosopher_set *philo);

#endif