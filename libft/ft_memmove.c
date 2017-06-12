/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/28 13:58:44 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (dest == src)
		return (dest);
	else if (src > dest)
		while (++i <= n)
			((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
	else
		while (++i <= n)
			((unsigned char *)dest)[n - i] = ((unsigned char *)src)[n - i];
	return (dest);
}
