/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:50:54 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/31 00:01:17 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TABLE_H
# define FT_TABLE_H

# include <stddef.h>
# include "ft_philosopher.h"
# include "ft_fork.h"
# include "ft_utils.h"
# include "ft_mutex_bflag.h"
# include "ft_args.h"
# include "ft_rules.h"

typedef struct s_table
{
	t_fork_set			forks_set;
//  size_t          num_philosophers;
//	t_philosopher	*philosophers;
    t_philosopher_set   philosophers_set;
    t_bool              start;
    t_mutex_bflag       end;
    t_rules             rules;
}	t_table;

void	ft_table_destroy(t_table * table);
t_bool  ft_table_pickup_forks(t_table *table, int num_philosopher);
t_bool  ft_table_isdead();
t_table ft_table_init(t_args args);

#endif