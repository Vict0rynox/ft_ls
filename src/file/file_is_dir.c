/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_is_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>
#include <sys/stat.h>
#include <ft_ls.h>

t_bool	file_is_dir(const char *pathname)
{
	struct stat	file_stat;

	if (pathname == NULL)
		return (D_FALSE);
	if (lstat(pathname, &file_stat) == 0)
	{
		if (S_ISDIR(file_stat.st_mode))
			return (D_TRUE);
		else
			return (D_FALSE);
	}
	return (D_FALSE);
}

t_bool	file_is_link(const char *pathname)
{
	struct stat file_stat;

	if (pathname == NULL)
		return (D_FALSE);
	if (lstat(pathname, &file_stat) == 0)
	{
		if (S_ISLNK(file_stat.st_mode))
			return (D_TRUE);
		else
			return (D_FALSE);
	}
	return (D_FALSE);
}
