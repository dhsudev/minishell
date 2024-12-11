/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:50:26 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/12/11 19:18:25 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>


// Run a builtin cmd
void handle_builtin(t_data *data, t_cmd *cmd) 
{
	(void)data;
	(void)cmd;
	if (ft_strncmp(cmd->path, "echo", 5) == 0)
		run_echo(cmd->args);
	// else if (ft_strncmp(cmd->path, "cd", 3) == 0)
	// else if (ft_strncmp(cmd->path, "pwd", 4) == 0)
	// else if (ft_strncmp(cmd->path, "export", 7) == 0)
	// else if (ft_strncmp(cmd->path, "unset", 6) == 0)
	// else if (ft_strncmp(cmd->path, "env", 4) == 0)
	// else if (ft_strncmp(cmd->path, "exit", 5) == 0))
}

#include <sys/wait.h>
// Case when it's only one command in prompt
// TODO: kill the child
void run_single(t_data *data, t_cmd *cmd)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        // Child process
        if (cmd->in_fd >= 0)
        {
            dup2(cmd->in_fd, STDIN_FILENO);
            close(cmd->in_fd);
        }

        if (cmd->out_fd >= 0)
        {
            dup2(cmd->out_fd, STDOUT_FILENO);
            close(cmd->out_fd);
        }

        if (cmd->builtin)
        {
            handle_builtin(data, cmd);
            exit(EXIT_SUCCESS); // Exit after running the built-in command
        }
        else if (execve(cmd->path, cmd->args, data->env_matrix) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

// Case when there are multiple commnads in prompt
void run_pipeline(t_data *data, t_cmd *cmd)
{
	(void)data;
	(void)cmd;	
}




void execute(t_data *data)
{
    data->cmd_list = group_cmd(data, data->token_list);
	print_cmd(data->cmd_list);
	if(!data->cmd_list)
		return ;
	if(!data->cmd_list->next)
		run_single(data, data->cmd_list);
    else
		run_pipeline(data, data->cmd_list);
}
