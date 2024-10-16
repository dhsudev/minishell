/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:30:48 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/10/15 21:29:46 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//PATH="bin/echo:bin/cat"
int			main(int ac, char **av, char **env)
{
	t_data data;
	
	(void)av;
	if(ac != 1)
	{
		printf("No args are allowed\n");
		exit(1);
	}
	copy_env(env, &data);
	while(42)
	{
		data.prompt = readline(PROMPT);
		//
		// do minishell
		//
		printf("%s\n", data.prompt);
		if(!ft_strncmp(data.prompt, "exit", 4))
			exit(0);
		free(data.prompt);
	}
	printf("%s\n", env[0]);
}
