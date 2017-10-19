#include <file.h>
#include <sys/stat.h>
#include <ft_ls.h>

t_bool	file_is_dir(const char *pathname)
{
	struct stat file_stat;

	if(lstat(pathname, &file_stat) == 0)
	{
		if(S_ISDIR(file_stat.st_mode))
			return (D_TRUE);
		else
			return (D_FALSE);
	}
	else
		error_message(pathname, "No such file or directory.");
	return (D_FALSE);
}