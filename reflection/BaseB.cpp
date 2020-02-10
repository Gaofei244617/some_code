#include "BaseB.h"
#include "cfg_factory.h"

void BaseB::info()
{
	std::cout << "This is Base B." << std::endl;
}
REGISTER_CFG_CLASS(BaseB);


