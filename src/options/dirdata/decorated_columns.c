/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorated_columns.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:10:19 by vvasilie          #+#    #+#             */
/*   Updated: 2017/10/24 12:10:19 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <options/options.h>
#include <stdio.h>
#include <file.h>
#include <sys/stat.h>
#include <ft_ls.h>

static char	*dir_total_size(t_list *lst_dirdata)
{
	int		size;
	t_file	*file;

	size = 0;
	while (lst_dirdata != NULL)
	{
		file = lst_dirdata->content;
		size += file->stat->st_blocks;
		lst_dirdata = lst_dirdata->next;
	}
	return (ft_itoa(size));
}

static void	size_increas(t_file_info_size *size, t_file_info *file_info)
{
	size_t	len;

	len = ft_strlen(file_info->lcount);
	size->lcount < len ? size->lcount = len : 0;
	len = ft_strlen(file_info->owner);
	size->owner < len ? size->owner = len : 0;
	len = ft_strlen(file_info->group);
	size->group < len ? size->group = len : 0;
	len = ft_strlen(file_info->size);
	size->size < len ? size->size = len : 0;
	len = ft_strlen(file_info->mimedate);
	size->mimedate < len ? size->mimedate = len : 0;
	len = ft_strlen(file_info->filename);
	size->filename < len ? size->filename = len : 0;
}

static char	*column_line_gen(t_file_info *info, t_file_info_size size)
{
	char	*line;

	line = ft_strjoin(ft_strjoin(info->type, info->acr), " ");
	line = ft_strjoin(line, ft_strjoin(
			ft_char_prefix(info->lcount, size.lcount, ' '), " "));
	line = ft_strjoin(line, ft_strjoin(
			ft_char_sufix(info->owner, size.owner, ' '), "  "));
	line = ft_strjoin(line, ft_strjoin(
			ft_char_sufix(info->group, size.group, ' '), "  "));
	line = ft_strjoin(line, ft_strjoin(
			ft_char_prefix(info->size, size.size, ' '), " "));
	line = ft_strjoin(line, ft_strjoin(
			ft_char_prefix(info->mimedate, size.mimedate, ' '), " "));
	line = ft_strjoin(line, info->filename);
	line = ft_strjoin(line, "\n");
	return (line);
}

static char	*column_gen(t_list *lst_dirdata)
{
	t_file_info_size	size;
	t_list				*lst_file;
	t_file_info			*file_info;
	char				*data;

	lst_file = NULL;
	data = ft_strnew(0);
	size = file_info_size_init();
	while (lst_dirdata != NULL)
	{
		file_info = new_file_info(lst_dirdata->content);
		size_increas(&size, file_info);
		ft_lstpush_back(&lst_file, file_info, 1);
		lst_dirdata = lst_dirdata->next;
	}
	while (lst_file != NULL)
	{
		data = ft_strjoin(data, column_line_gen(lst_file->content, size));
		free(lst_file->content);
		lst_file = lst_file->next;
	}
	return (data);
}

char		*decorated_columns(
	t_args *args, t_list *lst_dirdata, const char *dir)
{
	char	*data;

	data = ft_strnew(0);
	if (file_is_dir(dir))
	{
		if ((args->up_r || args->firt_path == NULL) &&
			((args->firt_path != NULL && ft_strcmp(args->firt_path, dir))
			|| args->firt_path == NULL))
			data = ft_strjoin(data, ft_strjoin(dir, ":\n"));
		if (lst_dirdata != NULL)
			data = ft_strjoin(ft_strjoin(data,
				ft_strjoin("total ", dir_total_size(lst_dirdata))), "\n");
	}
	data = ft_strjoin(data, column_gen(lst_dirdata));
	return (data);
}
