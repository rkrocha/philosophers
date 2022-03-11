/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:16:27 by rkochhan          #+#    #+#             */
/*   Updated: 2022/03/11 11:24:04 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include "ft_bool.h"

typedef long long t_time;

typedef struct s_philo
{
	int			id;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals_eaten;
	t_time		origin;
	pthread_t	thread;
}	t_philo;

t_bool	parse_validate_args(int argc, const char **argv, int input[5]);

t_philo	*init_philosophers(int input[5]);

t_time	current_time(void);
t_time	time_diff(t_time start, t_time end);

/*
** libft, but without libft, because that makes sense:
*/
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isspace(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strignore(const char *str, const char *set);

#endif
