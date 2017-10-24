/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_mimedate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:18 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:18 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>
#include <sys/stat.h>
#include <time.h>

char	*get_year(char *str_time)
{
	size_t	len;
	char	*year_start;
	char	*year;

	len = ft_strlen(str_time) - 2;
	year_start = str_time + len;
	while (len > 0 && *year_start != ' ')
		year_start--;
	year_start++;
	len = ft_strlen(year_start) - 1;
	year = ft_strnew(len);
	year = ft_strncpy(year, year_start, len);
	return (year);
}

char	*file_get_mimedate(t_file *file)
{
	char	*str_time;
	char	*year;
	time_t	curr_time;

	curr_time = time(NULL);
	str_time = ctime(&file->stat->st_mtimespec.tv_sec);
	if ((curr_time - 15778463) > file->stat->st_mtimespec.tv_sec ||
		file->stat->st_mtimespec.tv_sec > curr_time)
	{
		year = get_year(ft_strdup(str_time));
		str_time = ft_strjoin(ft_strjoin(ft_strsub(str_time, 4, 6),
						"  "), year);
	}
	else
		str_time = ft_strsub(str_time, 4, 12);
	return (str_time);
}
