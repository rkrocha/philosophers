/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:16:27 by rkochhan          #+#    #+#             */
/*   Updated: 2022/08/31 21:25:20 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define STATUS_DEAD		-1
# define STATUS_EATING		0
# define STATUS_SLEEPING	1
# define STATUS_THINKING	2

# define MSG_DEAD			"%6ld %3d died\n"
# define MSG_FORK			"%6ld %3d has taken a fork\n"
# define MSG_EATING			"%6ld %3d is eating\n"
# define MSG_SLEEPING		"%6ld %3d is sleeping\n"
# define MSG_THINKING		"%6ld %3d is thinking\n"

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include "ft_bool.h"

typedef long	t_time;

typedef struct s_philo
{
	int			id;
	int			status;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals_eaten;
	t_time		last_meal;
	t_time		origin;
	pthread_t	thread;
}	t_philo;

t_bool	parse_input(int argc, const char **argv, int input_args[5]);

t_philo	*init_philosophers(int input[5]);

t_bool	error_msg(const char *msg);
void	log_status(t_philo *philo, const char *msg);

t_time	current_time(void);
t_time	time_left_to_live(t_philo *philo);
t_time	time_diff(t_time start, t_time end);

/*
** libft, but without libft, because that makes sense:
*/
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size); ///////////////////////    size_t?
int		ft_isspace(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strignore(const char *str, const char *set);

#endif
