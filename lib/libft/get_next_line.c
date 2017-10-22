/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:37:31 by vvasilie          #+#    #+#             */
/*   Updated: 2017/04/17 12:37:32 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <strings.h>

t_file_lst	*ft_list_new(int fd)
{
	t_file_lst	*list;

	list = (t_file_lst *)malloc(sizeof(t_file_lst));
	list->buff = NULL;
	list->fd = fd;
	list->next = NULL;
	return (list);
}

t_file_lst	*ft_list_init(t_file_lst **list, int fd)
{
	t_file_lst	*curr_fiel;

	if (*list != NULL)
	{
		curr_fiel = *list;
		while (curr_fiel->next != NULL && curr_fiel->fd != fd)
			curr_fiel = curr_fiel->next;
		if (curr_fiel->fd != fd)
			curr_fiel->next = ft_list_new(fd);
		else
			return (curr_fiel);
		return (curr_fiel->next);
	}
	else
		*list = ft_list_new(fd);
	return (*list);
}

char		*ft_read_line(char *buff, int fd)
{
	char	*str;
	char	*tmp_str;

	buff = (buff == NULL || buff[0] != '\0') ? buff : NULL;
	if (buff && ft_strchr(buff, '\n'))
		return (buff);
	str = ft_strnew(BUFF_SIZE);
	while ((buff == NULL || ft_strchr(buff, '\n') == NULL) &&
			read(fd, str, BUFF_SIZE) > 0)
	{
		if (buff == NULL)
			buff = ft_strdup(str);
		else
		{
			tmp_str = buff;
			buff = ft_strjoin(tmp_str, str);
			free(tmp_str);
		}
		ft_bzero(str, BUFF_SIZE + 1);
	}
	free(str);
	return (buff);
}

int			ft_save_data(t_file_lst *cur_f, char **line)
{
	ssize_t			ln_size;
	char			*tmp_str;
	unsigned int	start;

	if (cur_f->buff == NULL)
		return (0);
	else if ((ln_size = (ssize_t)ft_strchr(cur_f->buff, '\n')) == 0)
		ln_size = (ssize_t)ft_strchr(cur_f->buff, '\0');
	ln_size -= (ssize_t)cur_f->buff;
	line != NULL ? *line = ft_strnew((size_t)ln_size) : 0;
	line != NULL ? *line = ft_strncpy(*line, cur_f->buff, (size_t)ln_size) : 0;
	if (ft_strchr(cur_f->buff, '\n'))
	{
		start = (unsigned int)(ft_strchr(cur_f->buff, '\n') - cur_f->buff + 1);
		tmp_str = ft_strsub(cur_f->buff, start, ft_strlen(cur_f->buff + start));
		free(cur_f->buff);
		cur_f->buff = tmp_str;
	}
	else
		cur_f->buff[0] = '\0';
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_file_lst	*list;
	t_file_lst			*curr_file;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	curr_file = ft_list_init(&list, fd);
	curr_file->buff = ft_read_line(curr_file->buff, fd);
	return (ft_save_data(curr_file, line));
}
