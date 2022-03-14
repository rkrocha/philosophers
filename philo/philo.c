/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:16:30 by rkochhan          #+#    #+#             */
/*   Updated: 2022/03/14 10:52:43 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_philo *self)
{
	log_status(self, MSG_FORK);
	log_status(self, MSG_FORK);
}

int	subroutine_eat(t_philo *self)
{
	t_bool	will_die;
	t_time	meal_duration;

	will_die = false;
	meal_duration = self->time_to_eat;
	if (self->time_to_eat >= self->time_to_die)
	{
		will_die = true;
		meal_duration = self->time_to_die;
	}
	log_status(self, MSG_EATING);
	self->last_meal = current_time();
	usleep(meal_duration * 1000);
	if (will_die)
		return (STATUS_DEAD);
	return (STATUS_SLEEPING);
}

int	subroutine_sleep(t_philo *self)
{
	t_bool	will_die;
	t_time	time_left;
	t_time	sleep_duration;

	will_die = false;
	sleep_duration = self->time_to_sleep;
	time_left = time_left_to_live(self);
	if (self->time_to_sleep >= time_left)
	{
		will_die = true;
		sleep_duration = time_left;
	}
	log_status(self, MSG_SLEEPING);
	usleep(sleep_duration * 1000);
	if (will_die)
		return (STATUS_DEAD);
	return (STATUS_THINKING);
}

int	subroutine_think(t_philo *self)
{
	t_time	thought_duration;

	thought_duration = time_left_to_live(self) - 10;
	log_status(self, MSG_THINKING);
	usleep(thought_duration * 1000);
	grab_forks(self);
	return (STATUS_EATING);
}

static void	*philo_routine(void *this_philo)
{
	t_philo				*self;
	static int (*const	routine[3])(t_philo *self) = {
		subroutine_eat, subroutine_sleep, subroutine_think};

	self = (t_philo *)this_philo;
	self->last_meal = self->origin;
	while (self->status != STATUS_DEAD)
		self->status = routine[self->status](self);
	log_status(self, MSG_DEAD);
	return (NULL);
}

static void	start_routines(t_philo *philos, int args[5])
{
	int		i;
	t_time	origin;

	i = 0;
	origin = current_time();
	while (i < args[0])
	{
		philos[i].origin = origin;
		pthread_create(&philos[i].thread, NULL, &philo_routine, &philos[i]); // error
		i++;
	}
	i = 0;
	while (i < args[0])
	{
		pthread_detach(philos[i].thread); // error condition
		i++;
	}
	usleep(3 * 1000 * 1000);
	return ;
}

int	main(int argc, const char **argv)
{
	int		args[5];
	t_philo	*philos;

	if (parse_validate_args(argc, argv, args) == false)
		return (1);
	// set_table
	philos = init_philosophers(args);
	start_routines(philos, args);
	// cleanup
	free(philos);
	return (0);
}
