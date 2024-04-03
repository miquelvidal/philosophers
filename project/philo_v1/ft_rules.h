/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:11:35 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/01 16:40:34 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RULES_H
# define FT_RULES_H

# include <pthread.h>
# include "ft_args.h"

typedef struct s_rules
{
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				number_eats;
//	pthread_mutex_t	log;
} t_rules;

t_rules	ft_rules_init(t_args args);
void	ft_rules_destroy(t_rules *rules);

#endif