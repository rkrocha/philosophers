/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:16:30 by rkochhan          #+#    #+#             */
/*   Updated: 2022/03/11 11:24:04 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, const char **argv)
{
	int		args[5];
	t_philo	*philos;

	if (parse_validate_args(argc, argv, args) == false)
		return (1);
	// set_table
	philos = init_philosophers(args);
	// start_routines
	// cleanup
	return (0);
}