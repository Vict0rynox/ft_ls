#include <ft_ls.h>
#include <file.h>
//TODO: add options -l -R -a -r -t
//TODO: обработать опции
	//TODO: могут быть подряд -Rla
	//TODO: могут быть последовательно -R -l -a
//TODO: Обработать каждый переданый путь по очереди
//TODO: Если путей нет, использовать текущую дерикторию в качестве пути

void error_message(char *message)
{
	write(STDOUT_FILENO, message, ft_strlen(message));
}

void print_file(t_list *lst_files)
{
	while (lst_files != NULL)
	{
		t_file *file;

		file = (t_file*)lst_files->content;
		printf("%s\t", file->name);

		lst_files = lst_files->next;
	}
}

void print_lisfile(t_list *lst_file)
{
	t_file *file;
	while (lst_file != NULL)
	{
		file = (t_file *) lst_file->content;
		printf("file: %s\n", file->path_name);
		lst_file = lst_file->next;
	}
	printf("\n\n");
}

void print_lispath(t_list *lst_path)
{
	while (lst_path != NULL)
	{
		printf("path: %s\n", (char*)lst_path->content);
		lst_path = lst_path->next;
	}
	printf("\n\n");
}

int main(int argc, char **argv)
{
	t_list *lst_path;
	t_options *options;

	lst_path = NULL;
	options = options_new();

	int i = 1;
	while (i < argc)
	{
		if(argv[i][0] == '-')
			options_init(options, argv[i]);
		else
			ft_lstpush_back(&lst_path, ft_strdup(argv[i]), sizeof(char*));
		i++;
	}
	if(lst_path == NULL)
		ft_lstpush_back(&lst_path, "./", sizeof(char*));
	ft_ls(options, lst_path);
	return (0);
}