#include <file.h>
#include <sys/stat.h>
#include <grp.h>

char *file_get_group(t_file *file)
{
	struct group *info;
	char *group;

	info = getgrgid(file->stat->st_gid);
	group = ft_strdup(info->gr_name);
	return (group);
}