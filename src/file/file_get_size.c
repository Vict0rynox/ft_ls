#include <file.h>
#include <sys/stat.h>

char *file_get_size(t_file *file)
{
	return ft_itoa((int)file->stat->st_size);
}