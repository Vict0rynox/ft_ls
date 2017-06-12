/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:27 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:48:57 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *str_ptr;

	str_ptr = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			str_ptr = (char *)str;
		str++;
	}
	if (*str == c)
		return ((char *)str);
	else
		return (str_ptr);
}
