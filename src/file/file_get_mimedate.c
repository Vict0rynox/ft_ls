#include <file.h>
#include <sys/stat.h>
#include <time.h>

char *file_get_mimedate(t_file *file)
{
	char *tmp;
	char *stime;
	size_t size;
	time_t curr_time;

	curr_time = time(NULL);
	if(curr_time - file->stat->st_mtimespec.tv_sec > 31556926)
		stime = ft_itoa((int)(1970 + (file->stat->st_mtimespec.tv_sec / 31556926)));
	else
	{
		tmp = ctime(&file->stat->st_mtimespec.tv_sec);
		size = ft_strlen(tmp) - 9;
		stime = ft_strnew(size);
		stime = ft_strncpy(stime, tmp, size);
	}
	return (stime);
}