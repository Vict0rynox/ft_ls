/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:06:56 by victorsecuring    #+#    #+#             */
/*   Updated: 2016/11/25 13:45:41 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*str_ptr;
	size_t	i;

	i = 0;
	str_ptr = (char *)str;
	while (i < n)
	{
		str_ptr[i] = '\0';
		i++;
	}
}
