#pragma once
#include <string>
#include <vector>
#include <cmath>
#include "Port.h"
#include "S_Window.h"

enum class Type
{
	NTYPE,
	SYSTEM,
	LOGIC,
	MATH,
	LIB
};

class BasicComponent
{
public:
	BasicComponent(Point position, std::string title ,Type type = Type::NTYPE, Uint16 inputPorts = 0, Uint16 outputPorts = 0, std::string luaCode = "");

	Type getType();
	Point getPosition();
	Rect getSize();
	Uint16 getInputPorts();
	Uint16 getOutputPorts();
	std::string getLuaCode();
	//Port* getInputPortsAt(Uint16 id);
	//Port* getOutputPortsAt(Uint16 id);

	virtual void drawBody();
	virtual void drawPorts();
	virtual void drawText();
	virtual void update();

private:
	Type type;
	Point pos;
	Uint16 inp, out;
	std::string code, title;
	//std::vector<Port*> inputPorts, outputPorts;
};

