#include <file.h>
#include <sys/stat.h>

char *file_get_lcount(t_file *file)
{
	return ft_itoa(file->stat->st_nlink);
}