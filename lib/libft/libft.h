/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <vvasilie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:49:16 by vvasilie          #+#    #+#             */
/*   Updated: 2016/11/25 13:52:49 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define ALP_DIFF ('a' - 'A')
# define DIG_TO_DIGC(c) ((c) >= '0' && (c) <= '9' ? (c) - '0' : 0)
# define DIGC_TO_DIG(dig) ((dig) + '0')
# define D_TRUE 1
# define D_FALSE 0
# define FT_TYPE_ATOI
# define CAT(X,TYPE) X##_##TYPE

typedef char		t_bool;

typedef enum		e_color
{
	RESET,
	RED,
	YELLOW,
	BLUE,
	GREEN,
	CYAN,
	MAGENTA
}					t_color_enum;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_digcount(int n);

void				*ft_memset(void *str, int c, size_t n);

void				ft_bzero(void *str, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memchr(const void *str, int c, size_t n);

int					ft_memcmp(const void *str1, const void *str2, size_t n);

size_t				ft_strlen(const char *str);

char				*ft_strdup(const char *str);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strncpy(char *dest, const char *src, size_t n);

char				*ft_strcat(char *dest, const char *src);

char				*ft_strncat(char *dest, const char *src, size_t n);

size_t				ft_strlcat(char *dest, const char *src, size_t n);

char				*ft_strchr(const char *str, int c);

char				*ft_strrchr(const char *str, int c);

char				*ft_strstr(const char *haystack, const char *needle);

char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);

int					ft_strcmp(const char *str1, const char *str2);

int					ft_strncmp(const char *str1, const char *str2, size_t n);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isnum(char *str);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(int n);

void				ft_putchar(char c);

void				ft_putstr(char const *s);

void				ft_putendl(char const *s);

void				ft_putnbr(int n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);

size_t				ft_lstsize(t_list *lst_head);

t_list				*ft_lstnew_c(void *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));

t_list				*ft_lstby_num(t_list *lst_head, unsigned int num);

t_list				*ft_lstpush_back(t_list **list, void *content,
									size_t content_size);

t_list				*ft_lstadd_back(t_list **list, t_list *lst);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_lstsort(t_list **list, int sort_func(void *, void *));

t_list				*ft_lstrev(t_list *lst);

void				ft_lstfree_widtoute_data(t_list **lst);

size_t				ft_strlenchr(const char *s, char c);

size_t				ft_strwordc(const char *s, char c);

void				ft_putstrc(char const *s, t_color_enum color);

void				ft_putstrc_fd(char const *s, int fd, t_color_enum color);

size_t				ft_putstrs(const char *str);

char				*ft_char_prefix(char *str, size_t len, char c);

char				*ft_char_sufix(char *str, size_t len, char c);

#endif
