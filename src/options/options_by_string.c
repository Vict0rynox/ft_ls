#include <options/options.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_ls.h>

void options_by_string(t_args *args, char *str)
{
	int i;

	i = 1;
	if (args != NULL && str != NULL && str[0] == '-' && ft_strlen(str) > 1)
	{
		while (str[i] != '\0')
		{
			if(str[i] == 'l')
				(args)->l = 1;
			else if(str[i] == 'R')
				(args)->R = 1;
			else if(str[i] == 'a')
				(args)->a = 1;
			else if(str[i] == 'r')
				(args)->r = 1;
			else if(str[i] == 't')
				(args)->t = 1;
			else if(str[i] == '1' || str[i] == '-')
				(void)args;
			else
				illegal_option(str+1);
			i++;
		}
	} else
		illegal_option(str);
}