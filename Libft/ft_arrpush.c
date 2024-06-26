/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:25:03 by dajimene          #+#    #+#             */
/*   Updated: 2024/06/11 13:30:36 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrpush(void ***arr, void *new_element)
{
	void	**new_arr;
	int		i;

	new_arr = malloc(sizeof(void *) * (ft_arrlen(*arr) + 2));
	if (!new_arr)
		return ;
	i = -1;
	while ((*arr)[++i])
		new_arr[i] = (*arr)[i];
	new_arr[i] = new_element;
	new_arr[i + 1] = NULL;
	free(*arr);
	*arr = new_arr;
}
