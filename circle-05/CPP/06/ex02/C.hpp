#ifndef C_HPP
# define C_HPP

#include "Base.hpp"

class C : public Base
{
private:

public:
	virtual void whoAmI() const;
	virtual ~C();
};

#endif // C_HPP
