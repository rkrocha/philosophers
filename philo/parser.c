/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:17:17 by rkochhan          #+#    #+#             */
/*   Updated: 2022/03/09 11:18:54 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	error_msg(const char *msg)
{
	printf("%s\n", msg);
	return (false);
}

static t_bool	is_valid_arg(const char *arg)
{
	if (ft_strignore(arg, "0123456789") == NULL)
		return (true);
	return (false);
}

t_bool	parse_valid_input(int argc, const char **argv, int input[5])
{
	unsigned char	i;

	if (argc < 5 || argc > 6)
		return (error_msg("Invalid number of args."));
	i = 0;
	while (i < argc - 1)
	{
		if (is_valid_arg(argv[i + 1]) == false)
			return (error_msg("Args must be integers."));
		input[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (input[0] == 0)
		return (error_msg("No philosophers defined."));
	if (argc == 5)
		input[i] = -1;
	return (true);
}
