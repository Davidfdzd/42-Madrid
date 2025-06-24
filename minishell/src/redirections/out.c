/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:16:36 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/21 15:13:10 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	process_out(char *file, char **err_msg)
{
	int		out;
	char	*tmp;

	out = -1;
	if (!*err_msg)
		out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out == -1 && !*err_msg)
	{
		tmp = ft_strjoin3("minishell: ", file, ": ");
		*err_msg = ft_strjoin(tmp, strerror(errno));
		free(tmp);
	}
	return (out);
}
