#include <file.h>
#include <sys/stat.h>
#include <ft_ls.h>

char *file_get_target_name(char *pathname)
{
	char *org_filename;
	char *tmp;
	ssize_t len;

	org_filename = ft_strnew(1024);
	len = readlink(pathname, org_filename, 1024);
	if(len < 0)
		error_message(pathname);
	tmp = org_filename;
	org_filename = ft_strncpy(ft_strnew((size_t)len), tmp, (size_t)len);
	free(tmp);
	return (org_filename);
}

char *file_get_filename(t_file *file)
{
	char *target_name;

	if(!S_ISLNK(file->stat->st_mode))
		return (ft_strdup(file->name));
	target_name = ft_strjoin(ft_strjoin(file->name, " -> "),
		file_get_target_name(file->path_name));
	return (target_name);
}