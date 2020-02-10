#include "BaseA.h"
#include "cfg_factory.h"
#include <cmath>

void BaseA::info()
{
	std::cout << "This is Base A." << std::endl;
}
REGISTER_CFG_CLASS(BaseA);
