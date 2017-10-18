/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:55:30 by vvasilie          #+#    #+#             */
/*   Updated: 2016/12/05 13:55:26 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrc_fd(char const *s, int fd, t_color color)
{
	if (fd >= 0 && s != NULL)
	{
		if (color == RESET)
			write(fd, "\x1b[0m", 4);
		else if (color == RED)
			write(fd, "\x1b[31m", 5);
		else if (color == YELLOW)
			write(fd, "\x1b[33m", 5);
		else if (color == BLUE)
			write(fd, "\x1b[34m", 5);
		else if (color == GREEN)
			write(fd, "\x1b[32m", 5);
		else if (color == CYAN)
			write(fd, "\x1b[36m", 5);
		else if (color == MAGENTA)
			write(fd, "\x1b[35m", 5);
		write(fd, s, ft_strlen(s));
		write(fd, "\x1b[0m", 4);
	}
}
