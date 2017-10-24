/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_pathname.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>

char	*file_get_pathname(char *path, char *name)
{
	char	*pathname;

	if (path[ft_strlen(path) - 1] != '/')
	{
		pathname = ft_strjoin(path, "/");
		pathname = ft_strjoin(pathname, name);
	}
	else
		pathname = ft_strjoin(path, name);
	return (pathname);
}
