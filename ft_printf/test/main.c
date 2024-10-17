#include "test.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	test_n;

	if (argc >= 3)
		return (1);
	else if (argc <= 1)
	{
		ft_test_base();
		ft_test_null();
		ft_test_char();
		ft_test_string();
		ft_test_digit();
		ft_test_int();
		ft_test_u();
		ft_test_x();
		ft_test_p();
	}
	else
	{
		test_n = atoi(argv[1]);
		if (test_n == 1)
			ft_test_base();
		else if (test_n == 2)
			ft_test_null();
		else if (test_n == 3)
			ft_test_char();
		else if (test_n == 4)
			ft_test_string();
		else if (test_n == 5)
			ft_test_digit();
		else if (test_n == 6)
			ft_test_int();
		else if (test_n == 7)
			ft_test_u();
		else if (test_n == 8)
			ft_test_x();
		else if (test_n == 9)
			ft_test_p();

	}
	return (0);
}
