/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:50:54 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/30 18:40:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TABLE_H
# define FT_TABLE_H

# include <stddef.h>
# include "ft_philosopher.h"
# include "ft_fork.h"
# include "ft_utils.h"

typedef struct s_table
{
	t_fork_set			forks_set;
//  size_t          num_philosophers;
//	t_philosopher	*philosophers;
    t_philosopher_set   philosophers_set;
    t_bool              start;
    t_bool              end;
}	t_table;

void	ft_table_destroy(t_table * table);
t_bool  ft_table_pickup_forks(t_table *table, int num_philosopher);

#endif