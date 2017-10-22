#include <options/options.h>
#include <stdlib.h>

t_args *new_args()
{
	t_args *options;

	options = (t_args*)malloc(sizeof(t_args));
	if (options == NULL)
		return (NULL);
	options->l = 0;
	options->G = 0;
	options->R = 0;
	options->a = 0;
	options->r = 0;
	options->t = 0;
	options->firt_path = NULL;
	options->alow_tire = 0;
	return (options);
}