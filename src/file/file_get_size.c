/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>
#include <sys/stat.h>
#include <ntsid.h>
#include <ft_ls.h>

char	*file_get_size(t_file *file)
{
	char	*size;

	if (!S_ISBLK(file->stat->st_mode) && !S_ISCHR(file->stat->st_mode))
		return (ft_itoa((int)file->stat->st_size));
	size = ft_strjoin(
			ft_itoa((int)major(file->stat->st_rdev)),
			ft_strjoin(",", ft_char_prefix(
				ft_itoa((int)minor(file->stat->st_rdev)), 4, ' ')));
	return (size);
}
