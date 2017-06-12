/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:24:10 by vvasilie          #+#    #+#             */
/*   Updated: 2016/12/05 13:26:26 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenchr(const char *s, char c)
{
	size_t size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}
