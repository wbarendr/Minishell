/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Peer <pde-bakk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 21:10:47 by peer          #+#    #+#                 */
/*   Updated: 2020/06/17 17:02:37 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>
# include <sys/stat.h>

int			g_ret;

typedef struct	s_vars
{
	char		**env1;
	int			ret;
	int			is_child;
	char		**paths;
	char		*home_path;
	int			**pipes;
	int			pids;
}				t_vars;

typedef struct	s_dup
{
	int			in;
	int			out;
	char		*input;
	char		*output;
	int			ispipe[2];
}				t_dup;

int				echo(char **args, t_vars *p, int fd);
void			our_exit(char **args, int forked);
int				cd(char **args, t_vars *p);
int				pwd(int fd);
void			argcheck(char **args, t_vars *p, t_dup *redirs, int forked);
void			fork_check(char **args, t_vars *p, t_dup *redirs);
int				env(char **args, t_vars *p, int fd);
int				bubble_sort(char **arr, int fd);
int				unset_new(char **args, t_vars *p);
char			**split_quotes2(char *str);
char			*ft_str3join(char *a, char *b, char *c);
void			get_abspath(char **abspath, t_vars *p, char **args);
void			ft_execute(char **args, t_vars *p, t_dup *redirs);
void			exec_checkifforked(char **args, t_vars *p, t_dup *redirs,
				int forked);
int				print_env_var(char *args, t_vars *p, int fd);
void			write_instant(char *str, int fd, t_vars *p);
char			**ft_split_q(char *s, char c);
int				main(void);

/*
** Utils
*/
int				ft_strcmp_equal(char *str1, char *str2);
char			*ft_strstrip(char *str, int i, int k);
int				get_next_line_q(int fd, char **line);
void			ft_putstr_fd_ret(char *str, int fd, t_vars *p);
void			remove_case(char **args);
void			block_ctrl_c(int sig);
void			block_ctrl_slash(int sig);
void			ft_putstr_fd_1(char *s, int fd);
int				find_equal(char *str);
char			*ft_strjoin_free(char *s1, char const *s2);
void			create_two_spaces(char **str);
char			*ft_strjoin_free_slash(char *s1, char const *s2, int n);
void			find_char(char *str, int *i, char d);
int				is_alpha_num(char c);
void			remove_quotes(char **args);
void			count_char2(int *i, int *co);
void			fill_char_c(char *str, char **new, int *i, int *n);
void			fill_char_e(char *str, char **new, int *i, int *n);
int				run_back_slash(char *str, int *index);
void			not_found(char *str);
void			get_environment2(char **env1, char *environ, int i);
void			p_is_child(t_vars *p);

/*
** Export
*/
int				check_valid_export(char *str);
int				export(char **args, t_vars *p, int fd);
char			**ft_split_equal(char *str);
int				find_match(char *env, char *new);
void			free_var(char **var, int *s);

/*
** Free_functions
*/
void			free_args(char **args);
void			free_line_cmds(char **cmds, char *line, int i);
void			free_arr_top_down(char **arr, int *i);
void			*ft_free_array(char **arr);
int				free_var_ret(char **var);

/*
** Gameloop
*/
char			*improve_line(char *line);
int				syntax_check(char *line);
char			**trimargs(char **args);
int				gameloop(t_vars *p, char *line);

/*
** Pipes and redirections
*/
int				free_line(char *line);
void			soul_goodman(t_vars *p, int *i);
void			close_fd(int fd);
void			redirect(char **args, t_dup *redirs);

#endif
