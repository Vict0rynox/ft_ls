#include <file.h>
#include <sys/stat.h>

char *file_get_filename(t_file *file)
{
	return (ft_strdup(file->name));
}