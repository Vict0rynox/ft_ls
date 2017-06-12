#include <stdio.h>
#include <libft.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/ttycom.h>
#include <sys/ioctl.h>
#include <sys/errno.h>

//usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]

//TODO: обработать опции
	//TODO: могут быть подряд -Rla
	//TODO: могут быть последовательно -R -l -a
//TODO: Обработать каждый переданый путь по очереди
//TODO: Если путей нет, использовать текущую дерикторию в качестве пути

typedef enum e_file_type t_file_type;
typedef struct s_file t_file;
typedef struct s_options t_options;
typedef struct s_opt_filter t_opt_filter;
typedef struct s_opt_decor t_opt_decor;
typedef struct s_opt_behavior t_opt_behavior;

//https://www.opennet.ru/cgi-bin/opennet/man.cgi?topic=lstat
// S_ISLNK(file_stat->st_mode)) ->  символьной ссылкой (Нет в POSIX.1-1996.)
// S_ISREG(file_stat->st_mode)) ->	обычным файлом
// S_ISDIR(file_stat->st_mode)) ->	каталогом
// S_ISCHR(file_stat->st_mode)) ->	символьным устройством
// S_ISBLK(file_stat->st_mode)) ->  блочным устройством
// S_ISFIFO(file_stat->st_mode)) ->	каналом FIFO
// S_ISSOCK(file_stat->st_mode)) ->	сокетом
struct s_file
{
	char *path;
	char *name;
	char *path_name;
	struct stat *stat;
	//...
};


struct s_opt_filter
{
	char a;
	char r;
	char t;
};

struct s_opt_decor
{
	char l;
	char G;
};


struct s_opt_behavior
{
	char R;
};


struct s_options
{
	t_opt_filter	filter;
	t_opt_decor		decor;
	t_opt_behavior	behavior;
};

t_file *file_new(char *path, char *name)
{
	t_file *file;

	file = (t_file*)malloc(sizeof(t_file));
	file->name = ft_strdup(name);
	file->path = ft_strdup(path);
	if(file->path[ft_strlen(file->path) - 1] != '/')
	{
		file->path_name = ft_strjoin(file->path, "/");
		file->path_name = ft_strjoin(file->path_name, file->name);
	}
	else
		file->path_name = ft_strjoin(file->path, file->name);

	return file;
}
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

void oprions_init(t_options *options, char *str)
{
	int i;

	i = 1;
	if (options != NULL && str != NULL && str[0] == '-' && ft_strlen(str) > 1)
	{
		while (str[i] != '\0')
		{
			if(str[i] == 'l')
				options->decor.l = 1;
			else if(str[i] == 'R')
				options->behavior.R = 1;
			else if(str[i] == 'a')
				options->filter.a = 1;
			else if(str[i] == 'r')
				options->filter.r = 1;
			else if(str[i] == 't')
				options->filter.t = 1;
			i++;
		}
	}
}


void file_remove(t_file **file)
{
	t_file *f;

	f = *file;
	free(f->path_name);
	free(f->name);
	free(f->path);
	free(f->stat);
	free(f);
	*file = NULL;
}

void ft_lstfree_widtoute_data(t_list **lst)
{
	t_list *lst_ptr;
	t_list *tmp;

	lst_ptr = *lst;
	while(lst_ptr != NULL)
	{
		tmp = lst_ptr;
		lst_ptr = lst_ptr->next;
		free(tmp);
	}
	*lst = NULL;
}

t_list *hiden_data_filter(t_list *lst_dirdata)
{
	t_file *file;

	if(lst_dirdata != NULL)
	{
		file = (t_file*)lst_dirdata->content;
		if(file->name[0] != '.')
			return (ft_lstnew_c(file, sizeof(t_file)));
	}
	return NULL;
}

/**
 * lst_dirdata [t_file]
 * @param options
 * @param lst_dirdata
 */
void filter_dirdata(t_opt_filter options, t_list **lst_dirdata)
{
	t_list *lst_ptr;

	if(options.a == 0)
	{
		lst_ptr = ft_lstmap(*lst_dirdata, hiden_data_filter);
		ft_lstfree_widtoute_data(lst_dirdata);
		*lst_dirdata = lst_ptr;
	}
	//TODO: options.t sorting
	//TODO: options.r reverse
}

/**
 * lst_dirdata[t_file]
 * @param options
 * @param lst_dirdata
 * @return
 */
char *decorated_dirdata(t_opt_decor options, t_list *lst_dirdata, char *dir)
{
	struct winsize wins;
	char *result;
	t_file *file;
	int column;

	int err;

	result = NULL;
	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &wins) == 0) {
		column = 4;
		//TODO: убрать, для отладки
		//printf("columns:%d,\t rows:%d\n", wins.ws_col, wins.ws_row);
	} else
		column = 4;

	//NOTHING OPTIONS!
	result = ft_strjoin(dir, ":\n");
	int i;
	i = 0;
	while (lst_dirdata != NULL)
	{
		file = (t_file*)lst_dirdata->content;
		result = ft_strjoin(result, file->name);
		if(i < column)
			result = ft_strjoin(result, "\t");
		else
		{
			result = ft_strjoin(result, "\n");
			i = 0;
		}
		i++;
		lst_dirdata = lst_dirdata->next;
	}

	result = ft_strjoin(result, "\n");
	return result;
}

t_list *behavior_dirdata(t_opt_behavior options, t_list *lst_dirdata)
{
	t_list *lst_add_path;

	lst_add_path = NULL;
	if(options.R == 1)
	{
		t_list *lst_ptr;
		t_file *file;

		lst_ptr = lst_dirdata;
		while (lst_ptr != NULL)
		{
			file = (t_file*)lst_ptr->content;
			if(S_ISDIR(file->stat->st_mode) && ft_strcmp(file->name, ".") && ft_strcmp(file->name, ".."))
				ft_lstpush_back(&lst_add_path, ft_strdup(file->path_name),
								sizeof(char *));
			lst_ptr = lst_ptr->next;
		}
	}
	return (lst_add_path);
}

void print_result(char *result)
{
	write(STDOUT_FILENO, result, ft_strlen(result));
}

//TODO разделим параметры на три вида:
	//TODO Поведенчиские
		//TODO R - рекурсивный поиск
	//TODO Филтры
		//TODO a - скрытые файлы и дериктории
		//TODO r - инвертировать сортировку
		//TODO t - сортировать по времени
	//TODO Параметры оформления
		//TODO l - вывеси ввиде таблици
		//TODO G - добавить цвет

int ft_ls(t_options *options, t_list *lst_path)
{
	//TODO: error handle.
	while (lst_path != NULL)
	{
		t_list *tmp;
		t_list *lst_dirdata;
		char *result;

		lst_dirdata = read_directory(lst_path->content);
		filter_dirdata(options->filter, &lst_dirdata);

		tmp = behavior_dirdata(options->behavior, lst_dirdata);
		if(tmp!= NULL)
		{
			ft_lstpush_back(&tmp, lst_path->next, sizeof(t_list));
			lst_path->next = tmp;
		}
		result = decorated_dirdata(options->decor, lst_dirdata, lst_path->content);
		print_result(result);
		lst_path = lst_path->next;
		//todo: free lst;
	}
	return 0;
}


t_options *options_new()
{
	t_options *options;

	options = (t_options*)malloc(sizeof(t_options));
	if(options != NULL)
	{
		options->decor.l = 0;
		options->decor.G = 0;
		options->behavior.R = 0;
		options->filter.a = 0;
		options->filter.r = 0;
		options->filter.t = 0;
	}
	return (options);
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
			oprions_init(options, argv[i]);
		else
			ft_lstpush_back(&lst_path, ft_strdup(argv[i]), sizeof(char*));
		i++;
	}
	if(lst_path == NULL)
		ft_lstpush_back(&lst_path, "./", sizeof(char*));
	ft_ls(options, lst_path);
	return (0);
}