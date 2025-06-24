/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:50:42 by csalazar          #+#    #+#             */
/*   Updated: 2025/05/06 16:21:13 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define CWD_ERR "shell-init: error retrieving current directory: getcwd: \
	cannot access parent directories: No such file or directory"
# define INV_ARG_ERR "Error: invalid input"
# define MALLOC_ERR "Error: malloc failed"
# define SIGINT_ERR "ERROR registering SIGINT handler"
# define SIGQUIT_ERR "ERROR registering SIGQUIT handler"
# define PATH_UPDATE_ERR "Error updating the path"
# define CD_TOO_MANY_ARGS_ERR "minishell: cd: too many arguments"
# define CD_NO_HOME_ERR "minishell: cd: HOME not set"
# define NO_PATH_ERR "Error getting the path"
# define UN_TOKEN_ERR "minishell: syntax error near unexpected token "
# define UN_TOKEN_NL_ERR "minishell: syntax error near unexpected token \
	`newline'"
# define UN_TOKEN_PIPE_ERR "minishell: syntax error near unexpected token `|'"
# define UN_TOKEN_2PIPE_ERR "minishell: syntax error near unexpected token `||'"

typedef enum e_interactive
{
	NON_INTERACTIVE,
	INTERACTIVE
}						t_interactive;

extern t_interactive	g_interactive;

typedef enum e_token_type
{
	WORD,
	IN,
	HERE_DOC,
	OUT,
	APPEND,
	PIPE
}						t_token_type;

typedef struct s_io
{
	int					in;
	int					out;
	int					com_count;
}						t_io;

typedef struct s_pipe
{
	int					**pipes;
	int					nb_pipes;
}						t_pipe;

typedef struct s_token
{
	t_token_type		type;
	char				*data;
	struct s_token		*next;
}						t_token;

typedef struct s_env
{
	char				*name;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct s_shell
{
	char				*pwd;
	int					pwd_unset;
	char				*oldpwd;
	char				*_;
	int					*hd;
	int					last_exit_status;
	int					*pids;
	int					launched_procs;
	t_pipe				*pipes;
	t_token				**token;
	t_env				**env;
	t_env				**export;
}						t_shell;

void					init_minishell(t_shell **shell, char **envp);
void					set_signal(void);
int						pipeline(t_shell *shell);
int						process_command(char **cmdargs, t_shell *shell, int i,
							t_token *segment);
t_io					*get_io(t_token *segment, int com_count,
							t_shell *shell);
void					exec_bin(t_shell *shell, char **cmdargs);
int						process_here_doc_redir(t_token *token, t_shell *shell);
int						process_input_redirections(t_token *token,
							t_shell *shell, int com_count);
int						process_output_redirections(t_token *token);
int						process_here_doc(char *delimiter, t_shell *shell);
int						process_in(char *file, char **err_msg);
int						process_out(char *file, char **err_msg);
int						process_append(char *file, char **err_msg);
int						exec_built_in(t_shell *minishell, char **cmdargs,
							t_io *io);
int						cmd_is_builtin(char *cmd);
int						ft_pwd(t_shell *shell, int out);
int						ft_cd(t_shell *shell, char **cmdargs, int out);
int						ft_echo(char **cmdargs, int out);
int						ft_env(t_shell *minishell, int out);
int						ft_export(t_shell *shell, char **cmdargs, int out);
int						ft_unset(t_shell *shell, char **cmdargs);
int						ft_exit(t_shell *shell, char **cmdargs, t_io *io);
void					get_token(char *line, t_shell *shell);
void					append_token(char *data, t_token_type type,
							t_shell *shell, int is_exp);
char					*add_expanded_variable(char *data, char *word, int *i,
							t_shell *shell);
void					toggle_quote(char quote, char *s_quote, char *d_quote);
char					*append_word_segment(char *data, char *word, int start,
							int end);
char					*expand_tilde(char *data, t_shell *shell);
char					*trim_line_quotes(char *line);
char					*expand_line(char *line, t_shell *shell);
char					*expand_here_doc(char *line, int has_quotes,
							t_shell *shell);
int						ft_isspace(char c);
int						isseparator(char c);
t_token					*get_last_token(t_token *token);
int						verify_token(t_token **token);
t_pipe					*init_pipes(t_token *token);
void					set_pipes(t_shell *shell, t_io *io);
void					close_pipes(t_pipe *pipes);
void					free_pipes(t_pipe *pipes);
int						upsert_env(t_env **env, char *envp);
t_env					*append_or_update(t_env **env, char *name, char *value);
int						is_valid_env_var(char *str);
t_env					*find_env_var_by_name(t_env **env, char *name);
char					*get_env_value(t_env **env, char *name);
char					**env_to_array(t_env *env);
void					print_sorted_env(t_env **env, int out);
int						len_2d_array(char **arr);
char					*ft_strjoin3(char *s1, char *s2, char *s3);
char					*get_last_cmdarg(char **cmdarg);
void					ft_exit_error(char *message, int status,
							t_shell *shell);
void					ft_error(char *message);
void					ft_error_concat(int count, ...);
void					ft_error_cd_not_file(char *file);
void					free_shell(t_shell *shell);
void					free_token(t_token **token);
void					free_split(char **split);
char					*ft_get_next_line(void);

#endif