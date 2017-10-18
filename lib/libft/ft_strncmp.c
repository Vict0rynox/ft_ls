/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:48:40 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n && str1[i] == str2[i])
	{
		i++;
		if (str1[i] == '\0' || str2[i] == '\0')
			break ;
	}
	return ((i >= n) ? 0 : ((unsigned char)str1[i] - (unsigned char)str2[i]));
}
