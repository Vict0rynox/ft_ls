#include <file.h>
#include <sys/stat.h>
#include <time.h>

//file->stat->st_mtimespec.tv_sec
char *file_get_mimedate(t_file *file)
{
	char *str_time;
	time_t  curr_time;

	curr_time = time(NULL);
	str_time = ctime(&file->stat->st_mtimespec.tv_sec);
	if((curr_time - 15778463) > file->stat->st_mtimespec.tv_sec ||
			file->stat->st_mtimespec.tv_sec > curr_time)
		str_time = ft_strjoin(ft_strjoin(ft_strsub(str_time, 4, 6), "  "),
				ft_strsub(str_time, 20, 4));
	else
		str_time = ft_strsub(str_time, 4, 12);
	str_time[12] = '\0';
	return (str_time);
}