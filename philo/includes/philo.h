/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:16:27 by rkochhan          #+#    #+#             */
/*   Updated: 2022/03/09 09:47:08 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define STATUS_EATING		0
# define STATUS_SLEEPING	1
# define STATUS_THINKING	2

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "ft_bool.h"
# include "ft_charsets.h"

typedef struct s_philo
{
	unsigned char	status;
	struct timeval	time_safe;
	struct timeval	time_current;
}	t_philo;

t_bool	parse_valid_input(int argc, const char **argv, int input[5]);

/*
** libft, but without libft, because that makes sense:
*/
int		ft_atoi(const char *str);
int		ft_isspace(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strignore(const char *str, const char *set);

#endif
