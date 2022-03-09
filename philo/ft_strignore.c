/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strignore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:14:54 by rkochhan          #+#    #+#             */
/*   Updated: 2022/03/07 17:52:48 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strignore(const char *str, const char *set)
{
	size_t		i;

	if (!str || !set)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (!ft_strchr(set, str[i]))
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
