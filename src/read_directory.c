#include <ft_ls.h>
#include <file.h>
#include <libgen.h>

char	*file_get_basename(char *pathname)
{
	char *cpathname;
	char *name;
	char *ptr_last_slash;

	cpathname = ft_strdup(pathname);
	if (cpathname[ft_strlen(cpathname) - 1] == '/')
		cpathname[ft_strlen(cpathname) - 1] = '\0';

	ptr_last_slash = cpathname;
	while (ft_strstr(ptr_last_slash, "/") != NULL)
		ptr_last_slash = ft_strstr(ptr_last_slash, "/");
	if(ptr_last_slash == cpathname)
		return (cpathname);
	name = ft_strnew(ft_strlen(ptr_last_slash+1));
	ft_strcpy(name, ptr_last_slash+1);
	free(cpathname);
	return (name);
}

char 	*file_get_path(char *pathname)
{
	char *path;
	char *name;

	name = file_get_basename(pathname);
	return name;
}

char	*file_get_pathname(char *path, char *name)
{
	char *pathname;

	if (path[ft_strlen(path) - 1] != '/')
	{
		pathname = ft_strjoin(path, "/");
		pathname = ft_strjoin(pathname, name);
	}
	else
		pathname = ft_strjoin(path, name);
	return (pathname);
}

t_list *read_file(char *pathname, t_list **lst_files)
{
	t_file *file;
	struct stat *file_stat;

	file = file_new(ft_strdup(pathname));
	file_stat = (struct stat*)malloc(sizeof(struct stat));
	if(lstat(file->path_name, file_stat) == 0)
		file->stat = file_stat;
	ft_lstpush_back(lst_files, file, 1);
	return (*lst_files);
}

//Передали файл /file.xtx
//Передали дерикторию /dir
//Передали содержимое дериктори /dir/
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

t_list *read_info(char *pathname)
{
	t_list *lst_files;
	struct stat file_stat;
	char *name;

	lst_files = NULL;
	name = file_get_basename(pathname);
	if(lstat(pathname, &file_stat) == 0) //файл открылся
	{
		if(S_ISDIR(file_stat.st_mode) && name[ft_strlen(name) - 1] == '/') //файл дериктория
			lst_files = read_directory_data(pathname, &lst_files);
		else
			lst_files = read_file(pathname, &lst_files);
		return (lst_files);
	}
	else
		error_message("ft_ls: No such file or directory.");
	return (lst_files);
}
