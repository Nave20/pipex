/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:35:48 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/20 17:35:56 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdlib.h>
# include <wait.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10
# endif

//-------------------------------GNL-------------------------------
char	*get_next_line(int fd);
char	*get_buffer_nl(char *buffer, size_t eol);
size_t	eol_detector(const char *buffer);
char	*get_buffer(int fd, char *buffer, ssize_t *stop);
void	*ft_memset(void *mem, int c, size_t size);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);

//-------------------------------LIBFT-------------------------------
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *src, const char *tofind, size_t size);
int		ft_printf(const char *s, ...);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	ft_putendl_fd(char *s, int fd);

//-------------------------------PIPEX-------------------------------
void	error_exit_one(char **cmd, char *path);
//_cmd
char	**get_path(char **env);
char	**get_cmd(char *str);
char	*path_finder(char **paths, char *cmd);
char	*path_finder2(char **paths, char *cmd);
//_utils
void	cleaner(char **str);
void	path_error(void);
void	error(void);
//_exec
void	cmd_1(char **argv, char **env, int *fd);
void	cmd_2(char **argv, char **env, int *fd);
//_dev
void	printer(char **a);
//_exec_2
int		fork_two(char **argv, char **env, int mfd[2], int *status);

#endif