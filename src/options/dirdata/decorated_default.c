#include <options/options.h>
#include <sys/ttycom.h>
#include <file.h>
#include <sys/ioctl.h>

char *decorated_default(t_list *lst_dirdata, const char *dir) {
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
