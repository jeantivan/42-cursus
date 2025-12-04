#include <iostream>
#include <cstdlib>
#include <ctime>

#include "test.hpp"

int main()
{
	srand((unsigned)time(NULL));

	no_signed_forms();
	buro_grade_too_low_to_execute();
	correct_execution();
	return 0;
}
