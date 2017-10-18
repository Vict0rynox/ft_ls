#include <sys/stat.h>
#include <stdio.h>
#include <math.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <options/dirdata/decorated.h>

/**
 * lst_dirdata[t_file]
 * @param options
 * @param lst_dirdata
 * @return
 */
char *decorated(t_opt_decor options, t_list *lst_dirdata, char *dir)
{
	if(options.l == 1)
		return decorated_columns(lst_dirdata, dir);
	return decorated_default(lst_dirdata, dir);
}