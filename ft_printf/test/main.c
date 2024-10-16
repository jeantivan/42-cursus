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
	}
	return (0);
}
