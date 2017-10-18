/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:46:45 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*str_ptr;
	size_t			i;

	i = 0;
	str_ptr = (unsigned char *)str;
	while (i < n)
	{
		if (*str_ptr == (unsigned char)c)
			return ((void *)str_ptr);
		i++;
		str_ptr++;
	}
	return (NULL);
}
