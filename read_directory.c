#include "ft_ls.h"

t_list *read_directory(char *dirname)
{
	t_list *lst_files;
	DIR *dir;
	t_file *file;
	struct stat *file_stat;

	lst_files = NULL;
	dir = opendir(dirname);
	if(dir != NULL)
	{
		struct dirent *dirent;

		while ((dirent = readdir(dir)) != NULL)
		{
			file = file_new(dirname, dirent->d_name);

			file_stat = (struct stat*)malloc(sizeof(struct stat));
			if(lstat(file->path_name, file_stat) == 0)
				file->stat = file_stat;
			ft_lstpush_back(&lst_files, file, sizeof(t_file*));
		}
		closedir(dir);
	}
	return lst_files;
}