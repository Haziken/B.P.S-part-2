#pragma once
#include "Utils.hpp"


class Port
{
public:
	Port(std::string name);

	bool isConnect();
	void setConnect(bool val);

	std::string getName();

private:
	std::string name;
	bool connect;
};
