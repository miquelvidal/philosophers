/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:31:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/02 18:21:45 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORK_H
# define FT_FORK_H

# include <stddef.h>
# include <pthread.h>

typedef struct s_fork
{
	size_t				num_fork;
	pthread_mutex_t		mutex;
}	t_fork;

typedef struct s_fork_set
{
	t_fork	*forks;
	size_t	num_forks;
}	t_fork_set;

t_fork		ft_fork_new(size_t num);
t_fork_set	ft_forks_init(size_t total);
void		ft_forks_destroy(t_fork_set *forks);
int			ft_fork_pickup(t_fork *fork);
int			ft_fork_drop(t_fork *fork);

#endif