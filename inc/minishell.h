/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:19:52 by ltrevin-          #+#    #+#             */
/*   Updated: 2025/01/07 17:24:22 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <libft/libft.h>
#include <tokenizer.h>
#include <error.h>

extern int     g_sig_exit_status;
void	copy_env(char **org_env, t_data *data);

// COLOR MACROS
# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define HEREDOC_NAME "/tmp/dancingshell_heredoc"

#define PROMPT MAGENTA "dancingShell🩰🦦" BLUE "> " RESET 


///////////// INIT STRUCTS
void    init_data(t_data *data);
void	init_cmd_data(t_cmd *cmd, t_token *tk_first, t_token *tk_last);


///////////// ENVIROMENT
void	copy_env(char **org_env, t_data *data);
void	free_env(t_env *env);
char	*get_env_value(t_env *env, char *key);


//////////// INIT STRUCTS
void	init_cmd_data(t_cmd *cmd, t_token *tk_first, t_token *tk_last);
void	init_data(t_data *data);

//////////// FREE utils
void	*free_ptr(void *ptr);
void	*free_cmd(t_cmd *cmd);
void	free_cmds(t_cmd *cmd_list);
void	free_env(t_env *env);
void	free_tokens(t_token *token_list);
void	free_token(t_token *token);
void	free_data(t_data *data, int env_flag);

//////////// SIGNALS
int     init_signals(int mode);
void    set_sig_ignore(int signum);
void    ctrlc_handler(int sig);
void    exit_signal_handler(int sig);



void    ft_free_split(char **split);

char	**env_as_matrix(t_env *env);

///////////// BUILTINS
int     run_echo(char **args);
void    run_pwd(t_data *data);
int     run_exit(t_cmd *cmd, t_data *data, int is_child);
void    run_env(t_data *data);
int     run_unset(char **cmd, t_data *data);


//////////// BUILTINS UTILS
int search_flags(char **cmd, char *cmd_name);

/////////// EXECUTION
t_cmd	*group_cmd(t_data *data, t_token *tk_list);
void execute(t_data *data);
int	handle_command_path(t_data *data, t_cmd *cmd, char *content, t_token *tk);

#endif

////////// BUG: Print utils, delete before submit
void	print_env(t_env *env);
void	print_cmd(t_cmd *cmd);