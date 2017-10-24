/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_by_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:19 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:19 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <options/options.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_ls.h>

static	void	fill_args(t_args *args, const char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 'l')
			(args)->l = 1;
		else if (str[i] == 'R')
			(args)->up_r = 1;
		else if (str[i] == 'a')
			(args)->a = 1;
		else if (str[i] == 'r')
			(args)->r = 1;
		else if (str[i] == 't')
			(args)->t = 1;
		else if (str[i] == '1')
			(void)args;
		else
			illegal_option(&str[i]);
		i++;
	}
}

void			options_by_string(t_args *args, char *str)
{
	if (args == NULL || str == NULL || str[0] != '-' || ft_strlen(str) <= 1)
		return (illegal_option(str));
	if (str[1] == '-' && str[2] == '\0')
		(args)->alow_tire = 1;
	else
		fill_args(args, str);
}
