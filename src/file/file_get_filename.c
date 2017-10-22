#include <file.h>
#include <sys/stat.h>
#include <ft_ls.h>

char *file_get_filename(t_file *file)
{
	char *org_filename;
	char *tmp;
	ssize_t len;

	if(!S_ISLNK(file->stat->st_mode))
		return (ft_strdup(file->name));
	org_filename = ft_strnew(1024);
	len = readlink(file->path_name, org_filename, 1024);
	if(len < 0)
		error_message(file->path_name);
	tmp = org_filename;
	org_filename = ft_strncpy(ft_strnew((size_t)len), tmp, (size_t)len);
	free(tmp);
	tmp = ft_strjoin(ft_strjoin(file->name, " -> "), org_filename);
	free(org_filename);
	return (tmp);
}