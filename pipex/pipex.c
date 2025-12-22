/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:19:22 by ttamae            #+#    #+#             */
/*   Updated: 2025/11/20 19:19:24 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	init_cmds(t_cmds *c, char **argv, char **envp)
{
	char	*path1;
	char	*path2;

	c->cmd1 = ft_split(argv[2], ' ');
	c->cmd2 = ft_split(argv[3], ' ');
	if (!c->cmd1 || !c->cmd2 || !c->cmd1[0] || !c->cmd2[0])
		return (1);
	path1 = find_path(c->cmd1[0], envp);
	path2 = find_path(c->cmd2[0], envp);
	if (path1)
	{
		free(c->cmd1[0]);
		c->cmd1[0] = path1;
	}
	if (path2)
	{
		free(c->cmd2[0]);
		c->cmd2[0] = path2;
	}
	return (0);
}

static int	get_exit_status(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

static void	close_fd(int fd)
{
	if (fd >= 0)
		close(fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_files			f;
	t_cmds			c;
	t_pids			p;

	if (argc != 5)
		return (write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40), 1);
	if (open_files_and_pipe(&f, argv[1], argv[4]))
		return (1);
	if (init_cmds(&c, argv, envp))
		return (close_all(f.pipefd, f.outfile, f.infile), 1);
	p.p1 = first_child(&f, &c, envp);
	close_fd(f.infile);
	close_fd(f.pipefd[1]);
	p.p2 = second_child(&f, &c, envp);
	close_fd(f.pipefd[0]);
	close_fd(f.outfile);
	waitpid(p.p1, NULL, 0);
	free_split(c.cmd1);
	free_split(c.cmd2);
	return (get_exit_status(p.p2));
}
