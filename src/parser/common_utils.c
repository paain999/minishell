/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:23:18 by dajimene          #+#    #+#             */
/*   Updated: 2024/05/29 19:03:18 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void 	ft_error_exit(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

char	**ft_cpy_arr(char **arr)
{
	char	**cpy;
	int		len;

	len = -1;
	while (arr[++len])
		;
	cpy = malloc(sizeof(char *) * (len + 1));
	if (!cpy)
		ft_error_exit(RED"Error: Malloc failed by ft_cpy_arr()"RST);
	len = -1;
	while (arr[++len])
	{
		printf(GREEN"arr[%d] = %s\n"RST, len, arr[len]);
		cpy[len] = ft_strdup(arr[len]);
		printf("cpy[%d] = %s\n", len, cpy[len]);
	}
	cpy[len] = (void*)0;
	return (cpy);
}
