/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:16:51 by ltrevin-          #+#    #+#             */
/*   Updated: 2025/01/13 22:46:42 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// ESTRUCTURA ENUMERACION TIPO DE TOKEN
typedef enum e_token_type
{
	SPC,
	WORD,
	SQ_STR,
	DQ_STR,
	PIPE,
	//____Redirections_____//
	INPUT,
	OUTPUT,
	APPEND,
	HERE_DOC,
	ENV_VAR,
}						t_token_type;

typedef struct s_cmd
{
	char				*path;
	int					nargs;
	char				**args;
	int					in_fd;
	int					out_fd;
	int					append_output;
	int					builtin;
	struct s_cmd		*next;
}						t_cmd;

//_____TOKEN_STRUCT_____//
typedef struct s_token
{
	enum e_token_type	type;
	char				*content;
	struct s_token		*next;
	struct s_token		*prev;

}						t_token;

//_____ENVIRONMENT_STRUCT_____//
typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
	struct s_env		*prev;
	int					match;
}						t_env;

//_____DATA_______STRUCT_____//
typedef struct s_data
{
	t_token				*token_list;
	t_env				*env;
	char				**path;
	char				*prompt;
	int					err_code;
	char				*err_msg;
	t_cmd				*cmd_list;
	char				**env_matrix;
}						t_data;

#endif