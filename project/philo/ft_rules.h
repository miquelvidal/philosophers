/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:11:35 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/30 23:53:06 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RULES_H
# define FT_RULES_H

# include "ft_args.h"

typedef struct s_rules
{
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				number_eats;
} t_rules;

t_rules	ft_rules_args_2_rules(t_args args);

#endif