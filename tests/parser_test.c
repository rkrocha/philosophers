#include "unit_tester.h"
#include "../philo/src/parser.c"
#include "../philo/src/ft_atoi.c"
#include "../philo/src/ft_isspace.c"
#include "../philo/src/ft_strchr.c"
#include "../philo/src/ft_strignore.c"

MU_TEST(all_mandatory_inputs_equal_100)
{
	int			input[5];
	const char	*argv[5] = {"whatever", "100", "100", "100", "100"};

	mu_assert_int_eq(0, parse_input(5, argv, input));
	mu_assert_int_eq(100, input[0]);
	mu_assert_int_eq(100, input[1]);
	mu_assert_int_eq(100, input[2]);
	mu_assert_int_eq(100, input[3]);
}

MU_TEST(one_mandatory_input_is_negative)
{
	int			input[5];
	const char	*argv[5] = {"whatever", "100", "-100", "100", "100"};

	mu_assert_int_eq(1, parse_input(5, argv, input));
}

MU_TEST(one_mandatory_input_is_not_int)
{
	int			input[5];
	const char	*argv[5] = {"whatever", "100", "100", "100", "hello"};

	mu_assert_int_eq(1, parse_input(5, argv, input));
}

MU_TEST(one_mandatory_input_is_zero)
{
	int			input[5];
	const char	*argv[5] = {"whatever", "100", "100", "00", "100"};

	mu_assert_int_eq(1, parse_input(5, argv, input));
}

MU_TEST(too_few_input_args)
{
	int			input[5];
	const char	*argv[4] = {"whatever", "100", "100", "100"};

	mu_assert_int_eq(1, parse_input(4, argv, input));
}

MU_TEST(too_many_input_args)
{
	int			input[5];
	const char	*argv[7] = {"whatever", "100", "100", "100", "100", "100", "100"};

	mu_assert_int_eq(1, parse_input(7, argv, input));
}

int	main(void)
{
	MU_RUN_TEST(all_mandatory_inputs_equal_100);
	MU_RUN_TEST(one_mandatory_input_is_negative);
	MU_RUN_TEST(one_mandatory_input_is_not_int);
	MU_RUN_TEST(one_mandatory_input_is_zero);
	MU_RUN_TEST(too_few_input_args);
	MU_RUN_TEST(too_many_input_args);

	MU_REPORT();
	return (MU_EXIT_CODE);
}
