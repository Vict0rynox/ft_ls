#include <file.h>

t_file *file_new(char *pathname)
{
	t_file *file;

	file = (t_file*)malloc(sizeof(t_file));
	file->path_name = pathname;
	file->name = ft_strdup(file_get_basename(pathname));
	file->path = ft_strdup(file_get_path(pathname));
	return file;
}