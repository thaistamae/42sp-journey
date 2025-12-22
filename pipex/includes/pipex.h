/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:26:11 by ttamae            #+#    #+#             */
/*   Updated: 2025/11/20 16:26:13 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/libft.h"

typedef struct s_cmds
{
	char	**cmd1;
	char	**cmd2;
}	t_cmds;

typedef struct s_files
{
	int		pipefd[2];
	int		infile;
	int		outfile;
}	t_files;

typedef struct s_pids
{
	pid_t	p1;
	pid_t	p2;
}	t_pids;

typedef struct s_child
{
	int		in;
	int		out;
	int		pipefd[2];
	char	**cmd;
	char	**envp;
}	t_child;

typedef struct s_child_args
{
	int		in;
	int		out;
	t_files	*f;
	char	**cmd;
	char	**envp;
}	t_child_args;

void	free_split(char **split);
char	*find_path(char *cmd, char **envp);
pid_t	first_child(t_files *f, t_cmds *c, char **envp);
pid_t	second_child(t_files *f, t_cmds *c, char **envp);
void	close_all(int *p, int out, int in);
int		open_files_and_pipe(t_files *f, char *in, char *out);

#endif
