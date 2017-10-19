#include <options/options.h>
#include <stdio.h>
#include <file.h>

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
char *decorated_columns(t_list *lst_dirdata, const char *dir)
{
	t_list *lst;
	char *data;
	char *line;
	char *tmp;

	lst = lst_dirdata;
	data = ft_strnew(0);
	while (lst != NULL)
	{
		t_file *file;
		file = lst->content;
		line = ft_strnew(254);
		sprintf(line, "%s%s %s %s %s %s %s %s\n",
				file_get_type(file),
				file_get_acr(file),
				file_get_lcount(file),
				file_get_owner(file),
				file_get_group(file),
				file_get_size(file),
				file_get_mimedate(file),
				file_get_filename(file)
		);
		tmp = data;
		data = ft_strjoin(data, line);
		free(tmp);
		lst = lst->next;
	}
	return (data);
}