#include <sys/stat.h>
#include <stdio.h>
#include <math.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <options/options.h>


/**
 * lst_dirdata[t_file]
 * @param args
 * @param lst_dirdata
 * @return
 */
char *decorated(t_args *args, t_list *lst_dirdata, char *dir)
{
	if(args->l == 1)
		return decorated_columns(args, lst_dirdata, dir);
	return decorated_default(args, lst_dirdata, dir);
}