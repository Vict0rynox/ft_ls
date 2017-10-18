/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:48:00 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	str1_len;
	size_t	str2_len;
	size_t	len;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	len = str1_len > str2_len ? str1_len : str2_len;
	return (ft_memcmp(str1, str2, len));
}
