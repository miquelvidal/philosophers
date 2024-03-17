/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:18:13 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/17 01:06:35 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

typedef unsigned char t_bool;

# define TRUE 1
# define FALSE 0

int		ft_utils_atoi(const char *number);
int		ft_utils_ctoi(char number);
int		ft_utils_isdigit(char character);
t_bool	ft_utils_contains_num(const char *str);

#endif