/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:57:38 by hawild            #+#    #+#             */
/*   Updated: 2024/04/22 17:02:34 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

char	*ft_get_path(char **envp, char *cmd)
{
	char	*path;
	char	*path_cmd;
	char	**path_split;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path_split = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_split[i])
	{
		path = ft_strjoin(path_split[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		if (access(path_cmd, F_OK) == 0)
			return (path_cmd);
		free(path_cmd);
		i++;
	}
	i = 0;
	while (path_split[i])
		free(path_split[i++]);
	return (0);
}

void	ft_execute(char *av, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(av, ' ');
	path = ft_get_path(envp, cmd[0]);
	if (!path)
		ft_error("Error in finding executable\n");
	execve(path, cmd, envp);
}
