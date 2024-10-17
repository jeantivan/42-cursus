#include "test.h"

void	ft_test_u(void)
{
	int test;

	printf(ANSI_COLOR_BLUE "\n--- Test printf behavior with u ---" ANSI_COLOR_RESET "\n");
	test = printf("%u", 1);
	printf("\nPrinting: 1 test = %i\n", test);
	test = printf("%u", 0);
	printf("\nPrinting: 0 test = %i\n", test);
	/* test = printf("%u", 123123132132132);
	printf("\nPrinting: long int test = %i\n", test); */
	test = printf("%u", -132);
	printf("\nPrinting: -132 test = %i\n", test);
	test = printf("%u", 0022);
	printf("\nPrinting: 0022 test = %i\n", test);
	test = printf("%u", 1);
	printf("\nPrinting: 1 test = %i\n", test);
	/* test = printf("%u", NULL);
	printf("\nPrinting: NULL test = %i\n", test); */
}
