/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:27:44 by rkochhan          #+#    #+#             */
/*   Updated: 2022/03/11 16:36:34 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philosophers(int input[5])
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ft_calloc(input[0], sizeof(t_philo));
	i = 0;
	while (i < input[0])
	{
		philos[i].id = i + 1;
		philos[i].status = STATUS_THINKING;
		philos[i].time_to_die = input[1];
		philos[i].time_to_eat = input[2];
		philos[i].time_to_sleep = input[3];
		i++;
	}
	return (philos);
}
