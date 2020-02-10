#include "cfg_factory.h"
#include "base.h"

int main()
{
	Base* my = CfgRegistry::GetObject("BaseA");
	Base* my2 = CfgRegistry::GetObject("BaseB");

	my->info();
	my2->info();
}