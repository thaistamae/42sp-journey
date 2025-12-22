/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:22:07 by ttamae            #+#    #+#             */
/*   Updated: 2025/11/20 19:22:09 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_safe(int fd)
{
	if (fd >= 0)
		close(fd);
}

void	close_all(int *p, int out, int in)
{
	if (p && p[0] >= 0)
		close(p[0]);
	if (p && p[1] >= 0)
		close(p[1]);
	if (out >= 0)
		close(out);
	if (in >= 0)
		close(in);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	open_files_and_pipe(t_files *f, char *in, char *out)
{
	f->infile = open(in, O_RDONLY);
	if (f->infile < 0)
	{
		perror(in);
		f->infile = open("/dev/null", O_RDONLY);
		if (f->infile < 0)
			return (1);
	}
	f->outfile = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (f->outfile < 0)
	{
		perror(out);
		close_safe(f->infile);
		return (1);
	}
	if (pipe(f->pipefd) < 0)
	{
		perror("pipe");
		close_safe(f->infile);
		close_safe(f->outfile);
		return (1);
	}
	return (0);
}
