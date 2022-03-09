/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:16:27 by rkochhan          #+#    #+#             */
/*   Updated: 2022/03/09 16:26:14 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "ft_bool.h"

typedef long long t_time;

t_bool	parse_valid_input(int argc, const char **argv, int input[5]);

t_time	current_time(void);
t_time	time_diff(t_time start, t_time end);

/*
** libft, but without libft, because that makes sense:
*/
int		ft_atoi(const char *str);
int		ft_isspace(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strignore(const char *str, const char *set);

#endif
