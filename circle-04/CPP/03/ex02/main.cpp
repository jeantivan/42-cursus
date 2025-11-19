#include <iostream>
#include "FragTrap.hpp"

int main() {
{
    std::cout << "\n====== Test Canonical orthodox form ======\n";

    std::cout << "\n=== Default constructor ===\n\n";
    FragTrap ft1;

    std::cout << "\n=== Parameter constructor ===\n\n";
    FragTrap ft2("Bob");

    std::cout << "\n=== Copy constructor ===\n\n";
    ft2.takeDamage(42);
    FragTrap ft3(ft2);
    ft2.showStats();
    ft3.showStats();

    std::cout << "\n=== Assign operator ===\n";
    ft1 = ft3;
    ft2.showStats();
    ft3.showStats();

    std::cout << "\n=== Destructors ===\n\n";

}

{
    std::cout << "\n====== Test Inheritance ======\n\n";

    ClapTrap *frag = new FragTrap("Frag-PTR");

    std::cout << "\n=== Own member function ===\n\n";
    static_cast<FragTrap *>(frag)->highFivesGuys();

    std::cout << "\n=== Inherited but overwritten functions  ===\n\n";

    frag->showStats();
    std::cout << "\n";

    frag->beRepaired(100);
    std::cout << "\n";

    frag->takeDamage(42);
    std::cout << "\n";

    frag->showStats();
    std::cout << "\n";

    frag->beRepaired(12);
    std::cout << "\n";


    frag->showStats();
    std::cout << "\n";

    frag->beRepaired(42);
    std::cout << "\n";

    frag->showStats();
    std::cout << "\n";

    frag->attack("you");
    std::cout << "\n";

    // for (int i = 0; i < 100; i++)
    //     frag->attack("you");

    // std::cout << "\n";

    // frag->beRepaired(100);

    // frag->takeDamage(42);

    // frag->showStats();

    std::cout << "\n=== Delete pointer ===\n\n";
    delete frag;
}










	return 0;
}
