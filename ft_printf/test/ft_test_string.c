#include "test.h"

void	ft_test_string(void)
{
	int	test;

	printf(ANSI_COLOR_BLUE "\n--- Test printf behavior with string ---" ANSI_COLOR_RESET "\n");
	test = printf("%s", "Hola mundo!");
	printf("\nPrinting: 'Hola mundo' test = %i\n", test);
	test = printf("%s", "");
	printf("\nPrinting: '' test = %i\n", test);
	/* test = printf("%s", (char *)NULL);
	printf("\nPrinting: NULL test = %i\n", test); */
	/* test = printf("%s", (char *)0);
	printf("\nPrinting (char *)0, test = %i\n", test); */

}
