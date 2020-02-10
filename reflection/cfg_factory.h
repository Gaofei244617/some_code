#pragma once

#include <unordered_map>

class Base;

class CfgRegistry
{
	using CfgCreator = Base * (*)();
	using CreatorMap = std::unordered_map<std::string, CfgCreator>;

public:
	static CreatorMap& Registry()
	{
		static CreatorMap g_creatorMap;
		return g_creatorMap;
	}

	static void AddCreator(std::string name, CfgCreator creator)
	{
		CreatorMap& registry = Registry();
		registry[name] = creator;
	}


	static Base* GetObject(std::string name)
	{
		return Registry()[name]();
	}
private:
	CfgRegistry() {}
};


class CfgRegister
{
public:
	CfgRegister(std::string name, Base* (*creator)())
	{
		CfgRegistry::AddCreator(name, creator);
	}
};

#define REGISTER_CFG_CLASS(name)  \
Base* Creator_##name()            \
{                                 \
    return new name();            \
}                                 \
static CfgRegister g_CfgRegister_##name(#name, Creator_##name);
