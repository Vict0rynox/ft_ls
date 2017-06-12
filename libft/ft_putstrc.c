/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:38:38 by vvasilie          #+#    #+#             */
/*   Updated: 2016/12/05 13:38:44 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrc(char const *s, t_color color)
{
	if (s != NULL)
	{
		if (color == RESET)
			write(1, "\x1b[0m", 4);
		else if (color == RED)
			write(1, "\x1b[31m", 5);
		else if (color == YELLOW)
			write(1, "\x1b[33m", 5);
		else if (color == BLUE)
			write(1, "\x1b[34m", 5);
		else if (color == GREEN)
			write(1, "\x1b[32m", 5);
		else if (color == CYAN)
			write(1, "\x1b[36m", 5);
		else if (color == MAGENTA)
			write(1, "\x1b[35m", 5);
		write(1, s, ft_strlen(s));
		write(1, "\x1b[0m", 4);
	}
}
