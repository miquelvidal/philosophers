/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:23:00 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/17 01:03:08 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_utils.h"

int	ft_utils_atoi(const char *number)
{
	int				num;
	char			sign;
	size_t			i;

	num = 0;
	i = 0;
	sign = 1;
	while (number[i] != '\0' && number[i] != '-' && ft_isdigit(number[i]))
		i++;
	if (number[i] == '-')
		sign = -1;
	while (number[i] != '\0')
	{
		if (ft_isdigit(number[i]) == FALSE)
			return (sign * num);
		num = ft_ctoi(number[i]) + 10 *num;
		i++;
	}
	return (sign * num);
}