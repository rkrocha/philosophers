/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:25:35 by rkochhan          #+#    #+#             */
/*   Updated: 2022/08/31 22:02:41 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Returns time since Epoch, in miliseconds.
*/
t_time	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

t_time	time_left_to_live(t_philo *philo)
{
	return (time_diff(current_time(), philo->last_meal + philo->time_to_die));
}

t_time	time_diff(t_time start, t_time end)
{
	return (end - start);
}
