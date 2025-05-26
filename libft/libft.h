/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:26:13 by maboualy          #+#    #+#             */
/*   Updated: 2025/05/26 13:35:58 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_atoi(const char *nptr);
int		ft_iswhitespace(int c);
int		ft_isascii(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_bzero(void *ptr, size_t n);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t n, size_t size);
int		ft_isprint(int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_isalnum(int c);
char	*ft_itoa(int n);
int		intasstrlen(int n);
void	*ft_memset(void *ptr, int c, size_t n);
char	**ft_split(char *s, char *c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_toupper(int c);
int		ft_isalpha(int c);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strrchr(const char *s, int c);

#endif
