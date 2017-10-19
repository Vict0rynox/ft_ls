#include <options/options.h>
#include <stdlib.h>
#include <libft.h>


void new_options_by_string(t_args **args, char *str)
{
	int i;

	if(*args == NULL)
		*args = new_args();
	i = 1;
	if (*args != NULL && str != NULL && str[0] == '-' && ft_strlen(str) > 1)
	{
		while (str[i] != '\0')
		{
			if(str[i] == 'l')
				(*args)->l = 1;
			else if(str[i] == 'R')
				(*args)->R = 1;
			else if(str[i] == 'a')
				(*args)->a = 1;
			else if(str[i] == 'r')
				(*args)->r = 1;
			else if(str[i] == 't')
				(*args)->t = 1;
			i++;
		}
	}
}