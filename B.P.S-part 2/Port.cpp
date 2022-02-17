#include "Port.h"

Port::Port(std::string name) : name(name)
{
	connect = false;
}

bool Port::isConnect()
{
	return connect;
}

void Port::setConnect(bool val)
{
	connect = val;
}

std::string Port::getName()
{
	return name;
}


