/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:46:46 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*str1_ptr;
	unsigned char	*str2_ptr;
	size_t			i;

	str1_ptr = (char unsigned *)str1;
	str2_ptr = (char unsigned *)str2;
	i = 0;
	while (i < n)
	{
		if (*str1_ptr == *str2_ptr)
		{
			str1_ptr++;
			str2_ptr++;
		}
		else
			return (*str1_ptr - *str2_ptr);
		i++;
	}
	return (0);
}
