#include "test.h"

void	ft_test_digit(void)
{
	int test;

	printf(ANSI_COLOR_BLUE "\n--- Test printf behavior with digit ---" ANSI_COLOR_RESET "\n");
	test = printf("%d", 1);
	printf("\nPrinting: 1 test = %i\n", test);
	test = printf("%d", 0);
	printf("\nPrinting: 0 test = %i\n", test);
	test = printf("%d", -20);
	printf("\nPrinting: -20 test = %i\n", test);
	test = printf("%d", 2147483647);
	printf("\nPrinting: 2147483647 test = %i\n", test);
	test = printf("%d", -2147483647);
	printf("\nPrinting: -2147483648 test = %i\n", test);
	test = printf("%u", 022);
	printf("\nPrinting: 022 test = %i\n", test);
	/* test = printf("%d", 2147483650);
	printf("\nPrinting: 2147483650 test = %i\n", test);
	test = printf("%d", -2147483650);
	printf("\nPrinting: -2147483650 test = %i\n", test);
	test = printf("%d", (int)NULL);
	printf("\nPrinting: (int)NULL test = %i\n", test);
	test = printf("%d", 12.2);
	printf("\nPrinting: 12.2 test = %i\n", test); */
}
