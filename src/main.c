#include <ft_ls.h>
#include <file.h>
//TODO: add options -l -R -a -r -t
//TODO: обработать опции
	//TODO: могут быть подряд -Rla
	//TODO: могут быть последовательно -R -l -a
//TODO: Обработать каждый переданый путь по очереди
//TODO: Если путей нет, использовать текущую дерикторию в качестве пути

void error_message(const  char *pathname)
{
	char *str;

	str = ft_strjoin("ft_ls: ", pathname);
	perror(str);
	free(str);
}

void illegal_option(const char *options)
{
	write(STDERR_FILENO, "ft_ls: illegal option -- ", 25);
	write(STDERR_FILENO, options, ft_strlen(options));
	write(STDERR_FILENO, "\nusage: ft_ls [-Raltr] [file ...]\n", 34);
	exit(1);
}

void error_read_info(char *pathname)
{
	char *str;
	str = ft_strjoin("ft_ls: ", pathname);
	perror(str);
	free(str);
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
		if(argv[i][0] == '-' && argv[i][1] != '\0')
			options_by_string(options, argv[i]);
		else
			ft_lstpush_back(&lst_path, ft_strdup(argv[i]), sizeof(char*));
		i++;
	}
	if(lst_path == NULL)
		ft_lstpush_back(&lst_path, "./", sizeof(char*));
	if(lst_path->next == NULL)
		options->firt_path = ft_strdup(lst_path->content);
	ft_ls(options, lst_path);
	return (0);
}