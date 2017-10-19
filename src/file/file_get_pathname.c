#include <file.h>

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
