/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:17:17 by rkochhan          #+#    #+#             */
/*   Updated: 2022/03/08 11:17:07 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	error_msg(const char *msg)
{
	printf("%s\n", msg);
	return (1);
}

static t_bool	is_valid_arg(const char *arg)
{
	if (ft_strignore(arg, DECIMAL_BASE) == NULL)
		return (TRUE);
	return (FALSE);
}

int	parse_input(int argc, const char **argv, int input[5])
{
	unsigned char	i;

	if (argc < 5 || argc > 6)
		return (error_msg("Invalid amount of args."));
	i = 1;
	while (i < argc)
	{
		if (!is_valid_arg(argv[i]))
			return (error_msg("Args must be larger than zero integers."));
		input[i - 1] = ft_atoi(argv[i]);
		if (input[i - 1] <= 0) // os tempos podem ser 0?
			return (error_msg("Args must be larger than zero integers."));
		i++;
	}
	if (argc == 5)
		input[i - 1] = 0;
	return (0);
}
