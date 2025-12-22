/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:55:43 by ttamae            #+#    #+#             */
/*   Updated: 2025/11/23 13:55:45 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

static void	safe_dup(int oldfd, int newfd)
{
	if (oldfd >= 0)
	{
		if (dup2(oldfd, newfd) < 0)
			perror("dup2");
	}
}

static void	exec_child(int in, int out, char **cmd, char **envp)
{
	safe_dup(in, STDIN_FILENO);
	safe_dup(out, STDOUT_FILENO);
	if (!cmd[0])
		exit(127);
	if (access(cmd[0], F_OK) != 0)
	{
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, ": command not found\n", 20);
		exit(127);
	}
	if (access(cmd[0], X_OK) != 0)
	{
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, ": Permission denied\n", 20);
		exit(126);
	}
	execve(cmd[0], cmd, envp);
	perror("execve");
	exit(1);
}

pid_t	first_child(t_files *f, t_cmds *c, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		close(f->pipefd[0]);
		exec_child(f->infile, f->pipefd[1], c->cmd1, envp);
	}
	return (pid);
}

pid_t	second_child(t_files *f, t_cmds *c, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		close(f->pipefd[1]);
		exec_child(f->pipefd[0], f->outfile, c->cmd2, envp);
	}
	return (pid);
}
