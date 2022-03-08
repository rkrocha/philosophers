/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:16:30 by rkochhan          #+#    #+#             */
/*   Updated: 2022/03/08 11:23:01 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, const char **argv)
{
	// t_philo	*table;
	int		input[5];

	printf("%s\n", "Hello from philosophers 😎");

	if (parse_input(argc, argv, input) != 0)
		return (1);
	// init_philosophers
	// start_chef
	// start_philosophers
	// cleanup
	return (0);
}
