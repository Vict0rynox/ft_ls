#include <options/options.h>
#include <stdio.h>
#include <file.h>
#include <sys/stat.h>
#include <ft_ls.h>

char	*dir_total_size(t_list *lst_dirdata)
{
	int size;
	t_file *file;

	size = 0;
	while (lst_dirdata != NULL)
	{
		file = lst_dirdata->content;
		size += file->stat->st_blocks;
		lst_dirdata = lst_dirdata->next;
	}
	return (ft_itoa(size));
}

//displaying Unix file types, permissions, number of hard links, owner, group, size, last-modified date and filename
//drwxr-xr-x  7 victorsecuring  staff    238 Oct 16 20:43 libft
//d - file type
// d - for dear
// - - for file
// ...
//[rwx]{3} - read,write,exec, for owner group and other/
//7 - number hard link
//victorsecuring - owner
//staff - owner,
//238 - size
//Oct 16 20:43 - last-modified date
//	Oct - manse
//	16 - day
//	20:43|2016.. - time if year is curr or year.
//	libft - file name


t_file_info	*new_file_info(t_file *file)
{
	t_file_info *file_info;

	file_info = malloc(sizeof(t_file_info));
	file_info->type = file_get_type(file);
	file_info->acr = file_get_acr(file);
	file_info->lcount = file_get_lcount(file);
	file_info->owner = file_get_owner(file);
	file_info->group = file_get_group(file);
	file_info->size = file_get_size(file);
	file_info->mimedate = file_get_mimedate(file);
	file_info->filename = file_get_filename(file);
	return (file_info);
}

void size_increas(t_file_info_size *size, t_file_info *file_info)
{
	size_t len;

	len = ft_strlen(file_info->lcount);
	size->lcount < len ? size->lcount = len : 0;
	len = ft_strlen(file_info->owner);
	size->owner < len ? size->owner = len : 0;
	len = ft_strlen(file_info->group);
	size->group < len ? size->group = len : 0;
	len = ft_strlen(file_info->size);
	size->size < len ? size->size = len : 0;
	len = ft_strlen(file_info->filename);
	size->filename < len ? size->filename = len : 0;
}

char *ft_char_prefix(char *str, size_t len, char c)
{
	char *pref;
	char *new_str;
	size_t count;

	count = len - ft_strlen(str);
	pref = ft_strnew(count);
	ft_memset(pref, c, count);
	new_str = ft_strjoin(pref, str);
	free(pref);
	free(str);
	return (new_str);
}

char *column_line_gen(t_file_info *info, t_file_info_size size)
{
	char *line;

	line = ft_strjoin(ft_strjoin(info->type, info->acr), " ");
	line = ft_strjoin(line, ft_strjoin(
			ft_char_prefix(info->lcount, size.lcount, ' '), " "));
	line = ft_strjoin(line, ft_strjoin(
			ft_char_prefix(info->owner, size.owner, ' '), "  "));
	line = ft_strjoin(line, ft_strjoin(
			ft_char_prefix(info->group, size.group, ' '), "  "));
	line = ft_strjoin(line, ft_strjoin(
			ft_char_prefix(info->size, size.size, ' '), " "));
	line = ft_strjoin(line, ft_strjoin(
			ft_char_prefix(info->mimedate, size.mimedate, ' '), " "));
	line = ft_strjoin(line, ft_strjoin(info->filename, " "));
	line = ft_strjoin(line, "\n");
	return (line);
}

t_file_info_size file_info_size_init()
{
	t_file_info_size size;

	size.lcount = 0;
	size.owner = 0;
	size.group = 0;
	size.size = 0;
	size.mimedate = 12;
	size.filename = 0;
	size.type = 1;
	size.acr = 9;
	return (size);
}

char *column_gen(t_list *lst_dirdata)
{
	t_file_info_size size;
	t_list *lst_file;
	t_file_info *file_info;
	char *data;

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

char	*decorated_columns(t_args *args, t_list *lst_dirdata, const char *dir)
{
	char *data;

	data = ft_strnew(0);
	if(file_is_dir(dir))
	{
		if(args->R)
			data = ft_strjoin(data, ft_strjoin(dir, ":\n"));
		data = ft_strjoin(ft_strjoin(data, ft_strjoin("total ", dir_total_size(lst_dirdata))), "\n");
	}
	data = ft_strjoin(data, column_gen(lst_dirdata));
	return (data);
}