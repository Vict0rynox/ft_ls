/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:45:40 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	int		flag;

	result = (0);
	flag = 1;
	while (*str != '\0' && (*str == '\n' || *str == '\t' || *str == '\r' ||
							*str == '\v' || *str == '\f' || *str == ' '))
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '+' || *str == '-')
		str++;
	else if (!ft_isdigit(*str))
		return (0);
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + DIG_TO_DIGC(*str);
		str++;
	}
	return ((int)(result * flag));
}
