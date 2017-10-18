/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:47:55 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char *ptr_str;

	ptr_str = (unsigned char *)str;
	while (*ptr_str != '\0')
	{
		if (*ptr_str == (unsigned char)c)
			return ((char *)ptr_str);
		ptr_str++;
	}
	if (*ptr_str == (unsigned char)c)
		return ((char *)ptr_str);
	return (NULL);
}
