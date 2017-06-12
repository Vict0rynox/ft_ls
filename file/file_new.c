#include "file.h"

t_file *file_new(char *path, char *name)
{
	t_file *file;

	file = (t_file*)malloc(sizeof(t_file));
	file->name = ft_strdup(name);
	file->path = ft_strdup(path);
	if(file->path[ft_strlen(file->path) - 1] != '/')
	{
		file->path_name = ft_strjoin(file->path, "/");
		file->path_name = ft_strjoin(file->path_name, file->name);
	}
	else
		file->path_name = ft_strjoin(file->path, file->name);

	return file;
}