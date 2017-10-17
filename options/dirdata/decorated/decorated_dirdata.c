#include <sys/stat.h>
#include <stdio.h>
#include <math.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "decorated_dirdata.h"

char *default_decorated(t_list *lst_dirdata, const char *dir) {
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

char *file_get_type(t_file *file)
{
	char *c;

	if(file == NULL)
		return NULL;
	c = ft_strdup("-");
	if (S_ISLNK(file->stat->st_mode))
		c = ft_strdup("l");
	else if (S_ISREG(file->stat->st_mode))
		c = ft_strdup("-");
	else if (S_ISDIR(file->stat->st_mode))
		c = ft_strdup("c");
	else if (S_ISCHR(file->stat->st_mode))
		c = ft_strdup("c");
	else if (S_ISBLK(file->stat->st_mode))
		c = ft_strdup("b");
	else if (S_ISFIFO(file->stat->st_mode))
		c = ft_strdup("p");
	else if (S_ISSOCK(file->stat->st_mode))
		c = ft_strdup("s");
	return (c);
}

char *file_get_acr(t_file *file)
{
	char *acr;

	if(file == NULL)
		return NULL;
	acr = ft_strdup("---------");
	if	(file->stat->st_mode & S_IRUSR)
		acr[0] = 'r';
	if	(file->stat->st_mode & S_IWUSR)
		acr[1] = 'w';
	if	(file->stat->st_mode & S_IXUSR)
		acr[2] = 'x';
	if	(file->stat->st_mode & S_IRGRP)
		acr[3] = 'r';
	if	(file->stat->st_mode & S_IWGRP)
		acr[4] = 'w';
	if	(file->stat->st_mode & S_IXGRP)
		acr[5] = 'x';
	if	(file->stat->st_mode & S_IROTH)
		acr[6] = 'r';
	if	(file->stat->st_mode & S_IWOTH)
		acr[7] = 'w';
	if	(file->stat->st_mode & S_IXOTH)
		acr[8] = 'x';
	return (acr);
}

char *file_get_owner(t_file *file)
{
	struct passwd *info;
	char *owner;

	info = getpwuid(file->stat->st_uid);
	owner = ft_strdup(info->pw_name);
	return (owner);
}

char *file_get_group(t_file *file)
{
	struct group *info;
	char *group;

	info = getgrgid(file->stat->st_gid);
	group = ft_strdup(info->gr_name);
	return (group);
}

char *file_get_mimedate(t_file *file)
{
	char *tmp;
	char *stime;
	size_t size;
	time_t curr_time;

	curr_time = time(NULL);
	if(curr_time - file->stat->st_mtimespec.tv_sec > 31556926)
		stime = ft_itoa((int)(1970 + (file->stat->st_mtimespec.tv_sec / 31556926)));
	else
	{
		tmp = ctime(&file->stat->st_mtimespec.tv_sec);
		size = ft_strlen(tmp) - 6;
		stime = ft_strnew(size);
		stime = ft_strncpy(stime, tmp, size);
	}
	return (stime);
}

char *file_get_filename(t_file *file)
{
	return (ft_strdup(file->name));
}

char *file_get_lcount(t_file *file)
{
	return ft_itoa(file->stat->st_nlink);
}

char *file_get_size(t_file *file)
{
	return ft_itoa((int)file->stat->st_size);
}

//displaying Unix file types, permissions, number of hard links, owner, group, size, last-modified date and filename
//drwxr-xr-x  7 victorsecuring  staff    238 Oct 16 20:43 libft
//d - file type
// d - for dear
// - - for file
// ...
//[rwx]{3} - read,write,exec, for owner group and other/
//7 - number hard link
//victorsecuring - owner
//staff - owner,
//238 - size
//Oct 16 20:43 - last-modified date
//	Oct - manse
//	16 - day
//	20:43|2016.. - time if year is curr or year.
//	libft - file name

char *decorated_columns(t_list *lst_dirdata, const char *dir)
{
	t_list *lst;
	char *data;
	char *line;
	char *tmp;

	lst = lst_dirdata;
	data = ft_strnew(0);
	while (lst != NULL)
	{
		t_file *file;
		file = lst->content;
		line = ft_strnew(254);
		sprintf(line, "%s%s %s %s %s %s %s %s\n",
			file_get_type(file),
			file_get_acr(file),
			file_get_lcount(file),
			file_get_owner(file),
			file_get_group(file),
			file_get_size(file),
			file_get_mimedate(file),
			file_get_filename(file)
		);
		tmp = data;
		data = ft_strjoin(data, line);
		free(tmp);
		lst = lst->next;
	}
	return (data);
}
/**
 * lst_dirdata[t_file]
 * @param options
 * @param lst_dirdata
 * @return
 */
char *decorated_dirdata(t_opt_decor options, t_list *lst_dirdata, char *dir)
{
	if(options.l == 1)
		return decorated_columns(lst_dirdata, dir);
	return default_decorated(lst_dirdata, dir);
}