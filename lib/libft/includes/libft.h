/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:11:23 by jcodina-          #+#    #+#             */
/*   Updated: 2024/03/03 16:50:06 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include "../src/get_next_line/get_next_line.h"

/* ************************************************************************** */
/*   Typedefs															      */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

enum e_capital_letters
{
	LOW = 0,
	HIGH = 1
};

/* ************************************************************************** */
/*   Functions															      */
/* ************************************************************************** */

/*									ARRAY								*/

void			ft_arrset(int *arr, const int d, const unsigned int len);
void			ft_arrsetl(long long *arr, const long long d,
					const unsigned int len);

/*									CHAR_TYPE								*/

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*									LIST									*/

void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
int				ft_lst_exists(t_list *lst, void *content,
					int (*compare)(void *, void *));
void			*ft_lst_remove(t_list **lst, void *content,
					int (*compare)(void *, void *));
void			*ft_lst_remove_at(t_list **lst, int index);
void			ft_lst_remove_all(t_list **lst, void *content,
					int (*compare)(void *, void *), void (*del)(void *));
t_list			*ft_lst_dup(t_list *lst_src, void *(*dup)(void *));

/*									MATH									*/

int				ft_max(int n1, int n2);
long long		ft_maxl(long long n1, long long n2);
int				ft_min(int n1, int n2);
long long		ft_minl(long long n1, long long n2);
int				ft_pow(const int base, const int power);
long long		ft_powl(const long long base, const long long power);
int				ft_abs(int n);
long long		ft_abs_l(long long n);

/*							STANDARD_INPUT_OUTPUT							*/

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_putstrlen_fd(char *s, int fd);
void			ft_putstrendl_fd(char *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
int				ft_putnbrlen_fd(long nb, int fd);
int				ft_putnbrlen_hex(long long nbr, int hex_type);
void			ft_putnbr_base(long long nbr, char *base);
int				ft_putnbrlen_base(long long nbr, char *base);

/*							STANDARD_LIBRARY								*/

void			*free_darray(void **strs, int n);
void			*ft_calloc(size_t count, size_t size);
int				ft_atoi(const char *nptr);
long long		ft_atol(const char *nptr);
char			*ft_itoa(const int n);
char			*ft_uitoa(const unsigned int n);

/*									STRINGS									*/

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memrchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, int len);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

/*								STRINGS MATRIX								*/

unsigned int	ft_strs_cols(const char **strs);
unsigned int	ft_strs_rows(const char **strs);
int				ft_strs_colcmp(char **strs, int col_a, int col_b);
int				ft_strs_rowcmp(char **strs, int row_a, int row_b);
char			*ft_strschr(const char **strs, const char c,
					int *row_out, int *col_out);
void			ft_strscpy(char **dst, const char **src);
void			ft_strsncpy(char **dst, char **src, int row);
char			*ft_strs_add_line(const char *str, char **strs);
void			ft_strs_clear(char **strs);
void			ft_strs_free(char **strs);
char			**ft_strsdup(const char **strs);

#endif
