/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:53:20 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/30 23:58:31 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rules.h"

t_rules	ft_rules_args_2_rules(t_args args)
{
	t_rules rules;

	rules.number_eats	= args.num_must_eat;
	rules.time_to_die	= args.time_to_die;
	rules.time_to_eat	= args.time_to_eat;
	rules.time_to_sleep = args.time_to_sleep;
	return (rules);
}