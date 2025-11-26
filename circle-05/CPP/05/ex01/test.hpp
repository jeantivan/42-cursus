#ifndef TEST_HPP
# define TEST_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define BOLD_PURPLE  "\033[1;35m"
#define BOLD_CYAN  "\033[1;36m"
#define BOLD_YELLOW  "\033[1;33m"
#define NO_COLOR  "\033[0m"
#define RST  "\033[0;39m"
#define GRAY  "\033[0;90m"
#define RED  "\033[0;91m"
#define GREEN  "\033[0;92m"
#define YELLOW  "\033[0;93m"
#define BLUE  "\033[0;94m"
#define MAGENTA  "\033[0;95m"
#define CYAN  "\033[0;96m"
#define WHITE  "\033[0;97m"
#define BG_GREEN  "\033[42;37m"

void correct_form();
void grade_too_high_form();
void grade_too_low_form();
void correct_signed_form();
void signed_twice_form();

#endif // TEST_HPP
