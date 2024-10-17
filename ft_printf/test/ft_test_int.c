#include "test.h"

void	ft_test_int(void)
{
		int test;

	printf(ANSI_COLOR_BLUE "\n--- Test printf behavior with int ---" ANSI_COLOR_RESET "\n");
	test = printf("%i", 1);
	printf("\nPrinting: 1 test = %i\n", test);
	test = printf("%i", 0);
	printf("\nPrinting: 0 test = %i\n", test);
	test = printf("%i", -20);
	printf("\nPrinting: -20 test = %i\n", test);
	test = printf("%i", 2147483647);
	printf("\nPrinting: 2147483647 test = %i\n", test);
	test = printf("%i", -2147483647);
	printf("\nPrinting: -2147483648 test = %i\n", test);
	test = printf("%u", 022);
	printf("\nPrinting: 022 test = %i\n", test);
	/* test = printf("%i", 2147483650);
	printf("\nPrinting: 2147483650 test = %i\n", test);
	test = printf("%i", -2147483650);
	printf("\nPrinting: -2147483650 test = %i\n", test);
	test = printf("%i", (int)NULL);
	printf("\nPrinting: (int)NULL test = %i\n", test); */
}
