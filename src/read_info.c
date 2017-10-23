#include <ft_ls.h>
#include <file.h>

t_list *read_file(char *pathname, t_list **lst_files)
{
	t_file *file;
	struct stat *file_stat;

	file = file_new(ft_strdup(pathname));
	file_stat = (struct stat*)malloc(sizeof(struct stat));
	if(lstat(file->path_name, file_stat) == 0)
	{
		file->stat = file_stat;
		ft_lstpush_back(lst_files, file, 1);
	}
	return (*lst_files);
}

t_list *read_directory_data(char *dirname, t_list **lst_files)
{
	DIR *dir;
	struct dirent *dirent;
	char *pathname;

	dir = opendir(dirname);
	if(dir != NULL)
	{
		while ((dirent = readdir(dir)) != NULL)
		{
			pathname = file_get_pathname(dirname, dirent->d_name);
			*lst_files = read_file(pathname, lst_files);
		}
		closedir(dir);
	}
	return *lst_files;
}

t_list *read_info(char *pathname, t_args *args)
{
	t_list *lst_files;
	t_bool is_dir;

	lst_files = NULL;
	if(args->l)
		is_dir = file_is_dir(pathname);
	else
		is_dir = file_is_adir(pathname);
	if(is_dir)
		lst_files = read_directory_data(pathname, &lst_files);
	else
		lst_files = read_file(pathname, &lst_files);
	return (lst_files);
}
