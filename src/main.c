#include <ft_ls.h>
#include <file.h>
//TODO: add options -l -R -a -r -t
//TODO: обработать опции
	//TODO: могут быть подряд -Rla
	//TODO: могут быть последовательно -R -l -a
//TODO: Обработать каждый переданый путь по очереди
//TODO: Если путей нет, использовать текущую дерикторию в качестве пути

void error_message(const  char *pathname, const char *message)
{
	write(STDOUT_FILENO, "ft_ls: ", 7);
	write(STDOUT_FILENO, pathname, ft_strlen(pathname));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, message, ft_strlen(message));
	write(STDOUT_FILENO, "\n", 1);
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
		if(argv[i][0] == '-')
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