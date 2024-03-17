/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_problem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:53:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/17 23:55:40 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_problem.h"

void	ft_problem_destroy(t_problem *problem)
{
	if (problem->forks != NULL)
	{
		ft_fork_destroy(problem->forks);
	}
	if (problem->philosophers != NULL)
	{
		ft_philosopher_destroy(problem->philosophers);
	}
}