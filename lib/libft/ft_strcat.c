/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:47:50 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;

	i = ft_strlen(dest);
	while (*src)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
