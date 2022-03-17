#include "unit_tester.h"
#include "mock_utils.c"
#include "../philo/parser.c"
#include "../philo/init.c"
#include "../philo/ft_atoi.c"
#include "../philo/ft_bzero.c"
#include "../philo/ft_calloc.c"
#include "../philo/ft_isspace.c"
#include "../philo/ft_strchr.c"
#include "../philo/ft_strignore.c"

/*
** PARSER:
*/
MU_TEST(all_mandatory_inputs_equal_100)
{
	int			input[5];
	const char	*argv[5] = {"whatever", "100", "100", "100", "100"};

	mu_assert_int_eq(true, parse_args(5, argv, input));
	mu_assert_int_eq(100, input[0]);
	mu_assert_int_eq(100, input[1]);
	mu_assert_int_eq(100, input[2]);
	mu_assert_int_eq(100, input[3]);
	mu_assert_int_eq(-1, input[4]);
}

MU_TEST(no_philosophers)
{
	int			input[5];
	const char	*argv[5] = {"whatever", "0", "100", "100", "100"};

	mu_assert_int_eq(false, parse_args(5, argv, input));
}

MU_TEST(one_mandatory_input_is_negative)
{
	int			input[5];
	const char	*argv[5] = {"whatever", "100", "-100", "100", "100"};

	mu_assert_int_eq(false, parse_args(5, argv, input));
}

MU_TEST(one_mandatory_input_is_not_int)
{
	int			input[5];
	const char	*argv[5] = {"whatever", "100", "100", "100", "hello"};

	mu_assert_int_eq(false, parse_args(5, argv, input));
}

MU_TEST(one_mandatory_input_is_zero)
{
	int			input[5];
	const char	*argv[5] = {"whatever", "100", "100", "00", "100"};

	mu_assert_int_eq(true, parse_args(5, argv, input));
}

MU_TEST(too_few_input_args)
{
	int			input[5];
	const char	*argv[4] = {"whatever", "100", "100", "100"};

	mu_assert_int_eq(false, parse_args(4, argv, input));
}

MU_TEST(too_many_input_args)
{
	int			input[5];
	const char	*argv[7] = {"whatever", "100", "100", "100", "100", "100", "100"};

	mu_assert_int_eq(false, parse_args(7, argv, input));
}

MU_TEST(optional_input_is_valid)
{
	int			input[5];
	const char	*argv[6] = {"whatever", "100", "100", "100", "100", "10"};

	mu_assert_int_eq(true, parse_args(6, argv, input));
	mu_assert_int_eq(100, input[0]);
	mu_assert_int_eq(100, input[1]);
	mu_assert_int_eq(100, input[2]);
	mu_assert_int_eq(100, input[3]);
	mu_assert_int_eq(10, input[4]);
}

MU_TEST(optional_input_is_zero)
{
	int			input[5];
	const char	*argv[6] = {"whatever", "100", "100", "100", "100", "0"};

	mu_assert_int_eq(true, parse_args(6, argv, input));
}

MU_TEST(optional_input_is_not_int)
{
	int			input[5];
	const char	*argv[6] = {"whatever", "100", "100", "100", "100", "abc"};

	mu_assert_int_eq(false, parse_args(6, argv, input));
}

MU_TEST_SUITE(parser_suite)
{
	MU_RUN_TEST(all_mandatory_inputs_equal_100);
	MU_RUN_TEST(no_philosophers);
	MU_RUN_TEST(one_mandatory_input_is_negative);
	MU_RUN_TEST(one_mandatory_input_is_not_int);
	MU_RUN_TEST(one_mandatory_input_is_zero);
	MU_RUN_TEST(too_few_input_args);
	MU_RUN_TEST(too_many_input_args);
	MU_RUN_TEST(optional_input_is_valid);
	MU_RUN_TEST(optional_input_is_zero);
	MU_RUN_TEST(optional_input_is_not_int);
}


/*
** INIT_PHILOS:
*/
MU_TEST(init_three_philos)
{
	int		input[5] = {3, 100, 101, 102};
	t_philo	*philos;

	philos = init_philosophers(input);

	mu_assert_int_eq(sizeof(t_philo) * input[0], sizeof(*philos) * input[0]);
	for (int i = 0; i < input[0]; i++)
	{
		mu_assert_int_eq(i + 1, philos[i].id);
		mu_assert_int_eq(STATUS_THINKING, philos[i].status);
		mu_assert_int_eq(input[1], philos[i].time_to_die);
		mu_assert_int_eq(input[2], philos[i].time_to_eat);
		mu_assert_int_eq(input[3], philos[i].time_to_sleep);
		mu_assert_int_eq(0, philos[i].meals_eaten);
	}
	free(philos);
}

MU_TEST(init_one_philo)
{
	int		input[5] = {1, 100, 101, 102};
	t_philo	*philos;

	philos = init_philosophers(input);

	mu_assert_int_eq(sizeof(t_philo) * input[0], sizeof(*philos) * input[0]);
	mu_assert_int_eq(1, philos[0].id);
	mu_assert_int_eq(STATUS_THINKING, philos[0].status);
	mu_assert_int_eq(input[1], philos[0].time_to_die);
	mu_assert_int_eq(input[2], philos[0].time_to_eat);
	mu_assert_int_eq(input[3], philos[0].time_to_sleep);
	mu_assert_int_eq(0, philos[0].meals_eaten);
	free(philos);
}

MU_TEST_SUITE(init_philos_suite)
{
	MU_RUN_TEST(init_three_philos);
	MU_RUN_TEST(init_one_philo);

}

int	main(void)
{
	MU_RUN_SUITE(parser_suite);
	MU_RUN_SUITE(init_philos_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
