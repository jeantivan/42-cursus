#ifndef A_HPP
# define A_HPP

#include "Base.hpp"

class A : public Base
{
private:

public:
	virtual void whoAmI() const;
	virtual ~A();
};

#endif // A_HPP
