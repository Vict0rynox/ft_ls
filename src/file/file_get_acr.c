#include <file.h>
#include <sys/stat.h>

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