#include <file.h>
#include <sys/stat.h>
#include <sys/xattr.h>

char *file_get_acr(t_file *file)
{
	char *acr;

	if(file == NULL)
		return NULL;
	acr = ft_strdup("--------- ");
	file->stat->st_mode & S_IRUSR ? acr[0] = 'r' : 0;
	file->stat->st_mode & S_IWUSR ? acr[1] = 'w' : 0;
	if(file->stat->st_mode & S_ISUID)
		acr[2] = (char)(file->stat->st_mode & S_IXUSR ? 's' : 'S');
	else
		file->stat->st_mode & S_IXUSR ? acr[2] = 'x' : 0;
	file->stat->st_mode & S_IRGRP ? acr[3] = 'r' : 0;
	file->stat->st_mode & S_IWGRP ? acr[4] = 'w' : 0;
	if(file->stat->st_mode & S_ISGID)
		acr[5] = (char)(file->stat->st_mode & S_IXGRP ? 's' : 'S');
	else
		file->stat->st_mode & S_IXGRP ? acr[5] = 'x' : 0;
	file->stat->st_mode & S_IROTH ? acr[6] = 'r' : 0;
	file->stat->st_mode & S_IWOTH ? acr[7] = 'w' : 0;
	if(file->stat->st_mode & S_ISVTX)
		acr[8] = (char)(file->stat->st_mode & S_IXOTH ? 't' : 'T');
	else
		file->stat->st_mode & S_IXOTH ? acr[8] = 'x' : 0;
	if (listxattr(file->path_name, NULL, 0, XATTR_NOFOLLOW) > 0)
		acr[9]= '@';
	return (acr);
}