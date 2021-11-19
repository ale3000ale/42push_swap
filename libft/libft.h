/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:34:18 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/12 12:12:10 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_clist
{
	void			*content;
	struct s_clist	*next;
	struct s_clist	*pre;
	int				last;
}				t_clist;

int				ft_strdigit(char *s);
int				ft_atoi(const char *str);
long			ft_latoi(const char *str);
size_t			ft_strlen(const char *str);
int				ft_strncmp(char *s1, char *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memmove(void *str1, const void *str, size_t n);
char			*ft_strdup(const char *s1);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
char			*ft_strnstr(const char *haystack, const char *needle, \
				size_t len);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				ft_isascii(int c);
size_t			ft_strlcat(char *dest, const char *src, size_t destsize);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
void			*ft_memchr(void const *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));

t_clist			*ft_clstnew(void *content);
void			ft_clstadd_front(t_clist **lst, t_clist *new);
int				ft_clstsize(t_clist *lst);
t_clist			*ft_clstlast(t_clist *lst);
void			ft_clstadd_back(t_clist **lst, t_clist *new);
void			ft_clstdelone(t_clist *lst, void (*del)(void*));
void			ft_clstclear(t_clist **lst, void (*del)(void*));
void			ft_clstiter(t_clist *lst, void (*f)(void *));
t_clist			*ft_clst_export(t_clist *lst);

char			*ft_freestrjoin(char *s1, char *s2);
void			ft_char_swap(char *a, char *b);
void			ft_swap(int *a, int *b);

int				get_next_line(int fd, char **line);

#endif
