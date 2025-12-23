#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <list>
#include "MutantStack.hpp"

int main() {
	srand(time(NULL));

{
	std::cout << "Testing MutantStack\n\n";

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "\nLoop 'MutantStack'\n\n";

	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

{
	std::cout << "Testing 'const MutantStack'\n\n";

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	const MutantStack<int> const_mstack(mstack);

	std::cout << "\nLoop 'const MutantStack' using const_iterator\n\n";

	MutantStack<int>::const_iterator it = const_mstack.begin();
	MutantStack<int>::const_iterator ite = const_mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// Compilation error
	// const_mstack.push(42);

}

{
	std::cout << "\nTest replace 'MutantStack' for 'std::list'\n\n";

	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.front() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "\nLoop 'std::list'\n\n";
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
}

{
	std::cout << "\nTest std::sort on MutantStack\n\n";

	MutantStack<int> ms;

	for(int i = 0; i < 10; i++)
	{
		int r = 1 + rand() % 30;
		std::cout << r << " ";
		ms.push(r);
	}
	std::cout << "\n";
	std::sort(ms.begin(), ms.end());
	for(MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";

}
	return 0;
}
