/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:36:56 by rkochhan          #+#    #+#             */
/*   Updated: 2022/03/15 19:23:41 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	error_msg(const char *msg)
{
	printf("%s\n", msg);
	return (false);
}

void	log_status(t_philo *philo, const char *msg)
{
	printf(msg, time_diff(philo->origin, current_time()), philo->id);
}
