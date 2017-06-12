/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:46:05 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*num;
	long	tmp;
	size_t	len;

	len = ft_digcount(n);
	num = ft_strnew(len);
	if (num != NULL)
	{
		if (n < 0)
		{
			*num = '-';
			tmp = (-1 * (long)n);
		}
		else
			tmp = n;
		len--;
		*num = (char)(tmp == 0 ? '0' : *num);
		while (tmp != 0)
		{
			num[len] = (char)DIGC_TO_DIG(tmp % 10);
			len--;
			tmp = tmp / 10;
		}
	}
	return (num);
}
