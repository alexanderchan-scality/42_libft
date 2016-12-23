/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 06:12:01 by achan             #+#    #+#             */
/*   Updated: 2016/12/22 06:12:03 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GENERAL_H
# define FT_GENERAL_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *b, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				*ft_memmove(void *dst, void const *src, size_t n);
void				*ft_memchr(void const *b, int c, size_t n);
int					ft_memcmp(void const *b1, void const *b2, size_t n);

int					ft_memichr(void const *b, int c, size_t n);
void				*ft_memndup(void const *b, size_t n);
void				*ft_remalloc(void *ptr, size_t old, size_t new);

size_t				ft_strlen(char const *s);
char				*ft_strdup(char const *s);
char				*ft_strcpy(char *dst, char const *src);
char				*ft_strncpy(char *dst, char const *src, size_t len);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strncat(char *s1, char const *s2, size_t len);
size_t				ft_strlcat(char *s1, char const *s2, size_t size);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
char				*ft_strstr(char const *s1, char const *s2);
char				*ft_strnstr(char const *s1, char const *s2, size_t len);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t len);

int					ft_atoi(char const *s);
int					ft_isupper(int c);
int					ft_islower(int c);
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

#endif
