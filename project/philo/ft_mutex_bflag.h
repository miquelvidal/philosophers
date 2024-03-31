/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_bflag.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:47:51 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/31 00:00:17 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MUTEX_BFLAG
# define FT_MUTEX_BFLAG

# include <pthread.h>
# include "ft_utils.h"

typedef struct s_mutex_bflag
{
    t_bool          value;
    pthread_mutex_t mutex;

} t_mutex_bflag;

t_mutex_bflag	ft_mutex_bvalue_init(t_bool value);
t_bool		ft_mutex_bvalue_get(t_mutex_bflag *flag);
void		ft_mutex_bvalue_set(t_mutex_bflag *flag, t_bool new_value);
void		ft_mutex_bvalue_destroy(t_mutex_bflag *flag);

#endif
