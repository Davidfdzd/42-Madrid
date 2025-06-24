/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:41:58 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/21 17:30:28 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	update_pwds(t_shell *shell)
{
	char	*tmp;

	tmp = ft_strdup(shell->pwd);
	if (shell->oldpwd)
		free(shell->oldpwd);
	shell->oldpwd = ft_strdup(shell->pwd);
	if (find_env_var_by_name(shell->env, "OLDPWD"))
		append_or_update(shell->env, ft_strdup("OLDPWD"),
			ft_strdup(shell->pwd));
	free(shell->pwd);
	shell->pwd_unset = 0;
	shell->pwd = getcwd(NULL, 0);
	if (!shell->pwd)
	{
		ft_error_concat(2, "minishell: cd: ", CWD_ERR);
		shell->pwd = ft_strjoin(tmp, "/..");
	}
	if (find_env_var_by_name(shell->env, "PWD"))
		append_or_update(shell->env, ft_strdup("PWD"), ft_strdup(shell->pwd));
	free(tmp);
	return (0);
}

static int	cd_home(t_shell *shell)
{
	char	*home;

	home = get_env_value(shell->env, "HOME");
	if (!home)
		return (ft_error(CD_NO_HOME_ERR), 1);
	if (!home[0])
		return (0);
	if (chdir(home) != 0)
		return (ft_error_cd_not_file(home), 1);
	return (update_pwds(shell));
}

static int	cd_previous(t_shell *shell, int out)
{
	if (find_env_var_by_name(shell->env, "OLDPWD"))
	{
		if (!get_env_value(shell->env, "OLDPWD")[0])
		{
			ft_putendl_fd(get_env_value(shell->env, "OLDPWD"), out);
			return (update_pwds(shell));
		}
		if (chdir(get_env_value(shell->env, "OLDPWD")) != 0)
			return (ft_error_cd_not_file(get_env_value(shell->env, "OLDPWD")),
				1);
		ft_putendl_fd(get_env_value(shell->env, "OLDPWD"), out);
		return (update_pwds(shell));
	}
	else if (shell->oldpwd[0])
	{
		if (chdir(shell->oldpwd) != 0)
			return (ft_error_cd_not_file(shell->oldpwd), 1);
		ft_putendl_fd(shell->oldpwd, out);
		return (update_pwds(shell));
	}
	return (ft_error("minishell: cd: OLDPWD not set"), 1);
}

int	ft_cd(t_shell *shell, char **cmdargs, int out)
{
	if (shell->pipes->nb_pipes > 0)
		return (0);
	else if (len_2d_array(cmdargs) > 2)
		return (ft_error(CD_TOO_MANY_ARGS_ERR), 1);
	else if (!cmdargs[1])
		return (cd_home(shell));
	else if (ft_strcmp(cmdargs[1], "-") == 0)
		return (cd_previous(shell, out));
	else
	{
		if (chdir(cmdargs[1]) != 0)
			return (ft_error_concat(4, "minishell: cd: ", cmdargs[1], ": ",
					strerror(errno)), 1);
		else
			return (update_pwds(shell));
	}
}
