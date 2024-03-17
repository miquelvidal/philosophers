/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_problem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:50:54 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/17 23:55:46 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROBLEM_H
# define FT_PROBLEM_H

# include <stddef.h>
# include "ft_philosopher.h"
# include "ft_fork.h"

typedef struct s_problem
{
    size_t          num_forks;
	t_fork			*forks;
    size_t          num_philosophers;
	t_philosopher	*philosophers;
}	t_problem;

void	ft_problem_destroy(t_problem * problem);

#endif