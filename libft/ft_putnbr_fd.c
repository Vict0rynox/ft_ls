/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:36:26 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:47:35 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num[12];
	long	tmp;
	size_t	len;

	ft_memset(&num, 0, 12);
	len = ft_digcount(n);
	if (n < 0)
	{
		*num = '-';
		tmp = (-1 * (long)n);
	}
	else
		tmp = n;
	len--;
	*num = (char)(tmp == 0 ? '0' : *num);
	while (tmp != 0)
	{
		num[len] = (char)DIGC_TO_DIG(tmp % 10);
		len--;
		tmp = tmp / 10;
	}
	write(fd, num, ft_strlen(num));
}
