#include <ft_ls.h>
#include <file.h>
#include <math.h>
//TODO: add options -l -R -a -r -t
//TODO: обработать опции
	//TODO: могут быть подряд -Rla
	//TODO: могут быть последовательно -R -l -a
//TODO: Обработать каждый переданый путь по очереди
//TODO: Если путей нет, использовать текущую дерикторию в качестве пути

void error_message(const  char *pathname)
{
	char *str;

	//str = ft_strjoin("ft_ls: ", pathname);
	str = ft_strjoin("ls: ", pathname);
	perror(str);
	free(str);
}

void illegal_option(const char *options)
{
	//write(STDERR_FILENO, "ft_ls: illegal option -- ", 25);
	write(STDERR_FILENO, "/bin/ls: illegal option -- ", 27);
	write(STDERR_FILENO, options, 1);
	//write(STDERR_FILENO, "\nusage: ft_ls [-Raltr] [file ...]\n", 34);
	write(STDERR_FILENO, "\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", 63);
	exit(1);
}

time_t	file_get_time(char *pathname)
{
	struct stat file_stat;

	if(lstat(pathname, &file_stat) == 0)
		return (file_stat.st_mtimespec.tv_sec);
	return (0);
}

int		time_sort(char *pathname1, char *pathname2)
{
	long result;

	if(pathname1 == NULL || pathname2 == NULL)
		return (NAN);
	result = file_get_time(pathname1) - file_get_time(pathname2);
	return ((int)result);
}

int		alpha_sort(char *pathname1, char *pathname2)
{
	if(pathname1 == NULL || pathname2 == NULL)
		return (NAN);
	return (ft_strcmp(pathname2, pathname1));
}

t_bool	file_is_adir(char *pathname)
{
	t_bool result;

	if(pathname == NULL)
		return (D_FALSE);
	if(file_is_dir(pathname))
		return (D_TRUE);
	pathname = file_get_target_name(pathname);
	if(file_is_dir(pathname))
		result = D_TRUE;
	else
		result = D_FALSE;
	if(pathname != NULL)
		free(pathname);
	return (result);
}

int		type_sort(char *pathname1, char *pathname2)
{
	if(pathname1 == NULL || pathname2 == NULL)
		return (NAN);
	if(file_is_dir(pathname1) && !file_is_dir(pathname2))
		return -1;
	if(file_is_dir(pathname1) && !file_is_dir(pathname1))
		return 1;
	return (0);
}

//файлы идут раньше (всегда)
//фильтровать по asc2
//фильтровать по флагам
void filter_args(t_args *args, t_list **list)
{
	if(list == NULL || args == NULL || *list == NULL)
		return ;
	ft_lstsort(list, (int (*)(void *, void *)) alpha_sort);
	if(args->t == 1)
		ft_lstsort(list, (int (*)(void *, void *)) time_sort);
	if(args->r == 1)
		*list = ft_lstrev(*list);
	ft_lstsort(list, (int (*)(void *, void *)) type_sort);
}

int main(int argc, char **argv)
{
	t_list *lst_path;
	t_args *options;

	lst_path = NULL;
	options = new_args();
	int i = 1;
	while (i < argc)
	{
		if(argv[i][0] == '-' && argv[i][1] != '\0' && !options->alow_tire && lst_path == NULL)
			options_by_string(options, argv[i]);
		else
			ft_lstpush_back(&lst_path, ft_strdup(argv[i]), sizeof(char*));
		i++;
	}
	if(lst_path == NULL)
		ft_lstpush_back(&lst_path, "./", sizeof(char*));
	if(lst_path->next == NULL)
		options->firt_path = ft_strdup(lst_path->content);
	filter_args(options, &lst_path);
	ft_ls(options, lst_path);
	return (0);
}