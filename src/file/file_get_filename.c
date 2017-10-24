/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_filename.c                                :+:      :+:    :+:   */
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

char	*file_get_target_name(char *pathname)
{
	char	*org_filename;
	char	*tmp;
	ssize_t	len;

	org_filename = ft_strnew(1024);
	len = readlink(pathname, org_filename, 1024);
	if (len >= 0)
	{
		tmp = org_filename;
		org_filename = ft_strncpy(ft_strnew((size_t)len), tmp, (size_t)len);
		free(tmp);
		return (org_filename);
	}
	return (NULL);
}

char	*file_get_filename(t_file *file)
{
	char	*target_name;

	if (!S_ISLNK(file->stat->st_mode))
		return (ft_strdup(file->name));
	if (ft_strcmp(file->path, ".") == 0)
		target_name = ft_strjoin(ft_strjoin(file->name, " -> "),
			file_get_target_name(file->path_name));
	else
		target_name = ft_strjoin(ft_strjoin(file->path_name, " -> "),
			file_get_target_name(file->path_name));
	return (target_name);
}
