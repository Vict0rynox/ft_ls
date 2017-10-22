#ifndef FT_LS_H
#define FT_LS_H

#include <stdio.h>
#include <libft.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/ttycom.h>
#include <sys/ioctl.h>
#include <sys/errno.h>
#include <options/options.h>

int ft_ls(t_args *args, t_list *lst_path);

t_list *read_directory_data(char *dirname, t_list **lst_file);

void error_message(const char *pathname);

void illegal_option(const char *options);

t_list *read_file(char *pathname, t_list **lst_files);

t_list *read_info(char *pathname);

char *ft_char_prefix(char *str, size_t len, char c);

#endif
