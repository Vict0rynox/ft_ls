/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:27 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:48:48 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	i;

	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	i = 0;
	while (src_ptr[i] && i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	while (i != n)
		dest[i++] = '\0';
	return (dest);
}
