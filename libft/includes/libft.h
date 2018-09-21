/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:30:01 by prippa            #+#    #+#             */
/*   Updated: 2017/11/20 18:01:14 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
************************************ Includes **********************************
*/

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf.h"

/*
************************************ Defines ***********************************
*/

# define ABS(x)		(((x) < 0) ? -(x) : (x))
# define MAX(a, b)	((a) > (b) ? (a) : (b))
# define MIN(a, b)	((a) < (b) ? (a) : (b))

# define MALLOC_ERR		"malloc failed"
# define OPEN_ERR		"open failed"
# define READ_ERR		"read failed"
# define OTHER_ERR		"some error hapend"

# define BUFF_SIZE 80

/*
************************************ Data **************************************
*/

typedef	struct		s_gnl
{
	char			*s;
	size_t			i;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_list2
{
	void			*content;
	size_t			content_size;
	struct s_list2	*next;
	struct s_list2	*prev;
}					t_list2;

/*
******************************* Functions **************************************
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
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
void				ft_lstdelone(t_list **lst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **lst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **lst, t_list *new_obj);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstpop(t_list **lst, void (*del)(void *, size_t));

t_list2				*ft_lst2new(void const *content, size_t content_size);
void				ft_lst2delone(t_list2 **obj, void (*del)(void *, size_t));
void				ft_lst2del_by_obj(t_list2 **start, t_list2 **end,
						t_list2 *obj, void (*del)(void *, size_t));
void				ft_lst2del(t_list2 **start, t_list2 **end,
						void (*del)(void *, size_t));
void				ft_lst2_push_front(t_list2 **start, t_list2 **end,
						t_list2 *new_obj);
void				ft_lst2_push_back(t_list2 **start, t_list2 **end,
						t_list2 *new_obj);
void				ft_lst2iter(t_list2 *start, void (*f)(t_list2 *elem));

int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_str_is_digit(const char *str);
int					ft_str_is_alpha(const char *str);
int					ft_str_is_upper(const char *str);
int					ft_str_is_lower(const char *str);
void				ft_str_to_lower(char **str);
void				ft_str_to_upper(char **str);
int					get_next_line(const int fd, char **line);
char				*ft_itoa_base(unsigned long long int num,
						int base, int letter);
char				**ft_arrnew(size_t y, size_t x, int c);
size_t				ft_arrlen(char **arr);
void				ft_arrdel(char ***arr);
short				ft_nbrlen(long long int nb);
void				ft_putarr(char **arr);
void				ft_putarr_fd(char **arr, int fd);
long long int		ft_atoi_base(const char *str, int base);
char				*ft_itoa_max(long long int n);
long long int		ft_atoi_max(char *str);
void				ft_clear(void);
void				*ft_memrev(void *dst, size_t n);
char				*ft_strjoin_free(char **dst, const char *src,
						size_t dstsize, size_t srcsize);
char				*ft_memjoin_free(void **dst, const void *src,
						size_t dstsize, size_t srcsize);
void				ft_perror_exit(const char *message);
int					ft_base(const char c);

#endif
