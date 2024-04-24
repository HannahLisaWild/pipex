/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:41:13 by hawild            #+#    #+#             */
/*   Updated: 2024/04/22 16:35:22 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_process(int *fd, char **cmd, char **envp, pid_t pid)
{
	int	infile_fd;
	int	outfile_fd;

	if (pid == 0)
	{
		infile_fd = open(cmd[1], O_RDONLY, 0777);
		if (infile_fd == -1)
			ft_error("Error opening infile\n");
		dup2(fd[1], STDOUT_FILENO);
		dup2(infile_fd, STDIN_FILENO);
		close(fd[0]);
		ft_execute(cmd[2], envp);
	}
	else if (pid != 0)
	{
		outfile_fd = open(cmd[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd == -1)
			ft_error("Error opening outfile\n");
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(fd[1]);
		ft_execute(cmd[3], envp);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
		ft_error("Error: wrong number of arguments\n");
	if (pipe(fd) == -1)
		ft_error("Error: creating the pipe\n");
	pid = fork();
	if (pid == -1)
		ft_error("Error: forking failed\n");
	if (pid == 0)
	{
		ft_process(fd, av, envp, pid);
	}
	waitpid(pid, NULL, 0);
	ft_process(fd, av, envp, pid);
	return (0);
}
