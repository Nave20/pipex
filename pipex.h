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

//-------------------------------LIBFT-------------------------------
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *src, const char *tofind, size_t size);
int		ft_printf(const char *s, ...);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *str);

//-------------------------------PIPEX-------------------------------
void	error_exit_one(char **cmd, char *path);
//_cmd
char	**get_path(char **env, int i);
char	**get_cmd(char *str);
char	*path_finder(char **paths, char *cmd);
char	*path_finder2(char **paths, char *cmd);
//_utils
void	cleaner(char **str);
void	path_error(void);
void	error(void);
void	error_two(char *path, char **cmd);
void	error_three(char **path, char **cmd);
//_exec
void	cmd_1(char **argv, char **env, int *fd);
void	cmd_2(char **argv, char **env, int *fd);
//_dev
void	printer(char **a);
//_exec_2
int		fork_two(char **argv, char **env, int mfd[2], int *status);

#endif