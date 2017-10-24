/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>
#include <sys/stat.h>

char	*file_get_type(t_file *file)
{
	char	*c;

	if (file == NULL)
		return (NULL);
	c = ft_strdup("-");
	if (S_ISLNK(file->stat->st_mode))
		c = ft_strdup("l");
	else if (S_ISREG(file->stat->st_mode))
		c = ft_strdup("-");
	else if (S_ISDIR(file->stat->st_mode))
		c = ft_strdup("d");
	else if (S_ISCHR(file->stat->st_mode))
		c = ft_strdup("c");
	else if (S_ISBLK(file->stat->st_mode))
		c = ft_strdup("b");
	else if (S_ISFIFO(file->stat->st_mode))
		c = ft_strdup("p");
	else if (S_ISSOCK(file->stat->st_mode))
		c = ft_strdup("s");
	return (c);
}
