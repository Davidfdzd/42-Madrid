/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:44:17 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/12 16:14:51 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	append_to_export(char *var, t_shell *shell)
{
	if (is_valid_env_var(var))
	{
		if (!ft_strchr(var, '='))
			append_or_update(shell->export, ft_strdup(var), NULL);
		else if ((ft_strchr(var, '=') + 1)[0] == '\0')
			append_or_update(shell->export, ft_substr(var, 0, ft_strchr(var,
						'=') - var), ft_strdup(""));
		else
			upsert_env(shell->export, var);
	}
}

int	ft_export(t_shell *shell, char **cmdargs, int out)
{
	int	i;
	int	upserted;

	i = 1;
	if (!cmdargs[i])
	{
		print_sorted_env(shell->export, out);
		return (0);
	}
	while (cmdargs[i])
	{
		append_to_export(cmdargs[i], shell);
		upserted = upsert_env(shell->env, cmdargs[i]);
		if (upserted == -1)
			ft_error_concat(3, "export: `", cmdargs[i],
				"': not a valid identifier");
		i++;
	}
	return (0);
}
