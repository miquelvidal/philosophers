/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:31:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/17 23:45:16 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORK_H
# define FT_FORK_H

# include <stddef.h>

typedef struct s_fork
{
	size_t num_fork;
}	t_fork;

t_fork	ft_fork_new(size_t num);
t_fork	*ft_fork_init(size_t total);
void	ft_fork_destroy(t_fork * forks);

#endif