#include "test.h"

void	ft_test_x(void)
{
		int test;

	printf(ANSI_COLOR_BLUE "\n--- Test printf behavior with x ---" ANSI_COLOR_RESET "\n");
	test = printf("%x", 1);
	printf("\nPrinting: 1 test = %i\n", test);
	test = printf("%x", 0);
	printf("\nPrinting: 0 test = %i\n", test);
	test = printf("%x", 256);
	printf("\nPrinting: 256 test = %i\n", test);
	test = printf("%x", 2147483647);
	printf("\nPrinting: 2147483647 test = %i\n", test);
	test = printf("%x", -2147483647);
	printf("\nPrinting: -2147483648 test = %i\n", test);
	test = printf("%x", 022);
	printf("\nPrinting: 022 test = %i\n", test);
}
